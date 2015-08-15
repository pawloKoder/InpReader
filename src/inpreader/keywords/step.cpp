#include "keywords/step.h"

#include <functional>
#include <vector>
#include <iostream>

#include "basic.h"
#include "keywords/boundary.h"
#include "keywords/cload.h"
#include "keywords/dsload.h"
#include "keywords/dynamic.h"
#include "keywords/static.h"
#include "model.h"
#include "settings.h"
#include "tokens/keyword.h"


const std::string Keywords::Step::keyName = "Step";
const std::string Keywords::Step::keyEndName = "End Step";


Keywords::Step::Step(Keyword* parent) : Keyword(parent)
{}


Keywords::Keyword * Keywords::Step::appendDataLine(const Tokens::DataLine*)
{
	return this;
}


Keywords::Keyword * Keywords::Step::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<Keyword*()> > > possibleChildren = {
		std::make_pair(Boundary::keyName, [this](){ return new Boundary(this); }),
		std::make_pair(CLoad::keyName, [this](){ return new CLoad(this); }),
		std::make_pair(DSLoad::keyName, [this](){ return new DSLoad(this); }),
		std::make_pair(Dynamic::keyName, [this](){ return new Dynamic(this); }),
		std::make_pair(Static::keyName, [this](){ return new Static(this); }),
	};

	for (auto childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = std::shared_ptr <Keywords::Keyword>(childDef.second());
			children.push_back(child);
			return child.get();
		}
		
	if (token->name == keyEndName) {
		return parent;
	}

	
	if (InpReader::verboseUnknownKeyword)
		std::cout << "Unknown Keyword form Step: " << token->name << std::endl;

	return this;
}


void Keywords::Step::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "Step: Append to model" << std::endl;
	
	InpReader::Step step;
	step.name = name;

	for (auto child : children) {
		child->appendToStep(&step, model);
	}

	model->append(step);
}


void Keywords::Step::addParams(const std::map< std::string, std::string >& params)
{
	auto t = params.find("name");
	if (t != params.end())
		name = t->second;
}
