#include "keywords/assembly.h"

#include <iostream>
#include <cstdio>

#include "keywords/elementset.h"
#include "keywords/nodeset.h"
#include "keywords/instance.h"
#include "keywords/surface.h"
#include "keywords/tie.h"
#include "settings.h"
#include "tokens/keyword.h"

#include <functional>
#include <vector>


const std::string Keywords::Assembly::keyName = "Assembly";
const std::string Keywords::Assembly::keyEndName = "End Assembly";


Keywords::Assembly::Assembly(Keyword* parent) : Keyword(parent)
{}


Keywords::Keyword * Keywords::Assembly::appendDataLine(const Tokens::DataLine*)
{
	return this;
}


Keywords::Keyword * Keywords::Assembly::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<Keyword*()> > > possibleChildren = {
		std::make_pair(ElementSet::keyName, [this](){ return new ElementSet(this); }),
		std::make_pair(NodeSet::keyName, [this](){ return new NodeSet(this); }),
		std::make_pair(Instance::keyName, [this](){ return new Instance(this); }),
		std::make_pair(Surface::keyName, [this](){ return new Surface(this); }),
		std::make_pair(Tie::keyName, [this](){ return new Tie(this); }),
	};

	for (const auto & childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = childDef.second();
			child->addParams(token->parameters);
			children.push_back(std::unique_ptr <Keywords::Keyword>(child));
			return child;
		}
		
	if (token->name == keyEndName) {
		return parent;
	}

	std::cout << "Unknown Keyword form Assembly: " << token->name << std::endl;

	return this;
}


void Keywords::Assembly::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "Assembly: Append to model" << std::endl;
	
	//TODO: Add assembly to the model.

	for (const auto & child : children)
		child->appendToModel(model);
}
