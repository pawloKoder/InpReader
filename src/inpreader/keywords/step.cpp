#include "keywords/step.h"

#include <functional>
#include <vector>
#include <iostream>

#include "keywords/boundary.h"
#include "keywords/dsload.h"
#include "keywords/static.h"
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
		std::make_pair(DSLoad::keyName, [this](){ return new DSLoad(this); }),
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

	std::cout << "Unknown Keyword form Step: " << token->name << std::endl;

	return this;
}