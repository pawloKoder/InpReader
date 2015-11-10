#include "keywords/part.h"

#include <iostream>
#include <cstdio>

#include "keywords/element.h"
#include "keywords/elementset.h"
#include "keywords/heading.h"
#include "keywords/node.h"
#include "keywords/nodeset.h"
#include "keywords/material.h"
#include "keywords/preprint.h"
#include "settings.h"
#include "tokens/keyword.h"

#include <functional>
#include <vector>


const std::string Keywords::Part::keyName = "Part";
const std::string Keywords::Part::keyEndName = "End Part";


Keywords::Part::Part(Keyword* parent) : Keyword(parent)
{}


Keywords::Keyword * Keywords::Part::appendDataLine(const Tokens::DataLine*)
{
	return this;
}


Keywords::Keyword * Keywords::Part::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<Keyword*()> > > possibleChildren = {
		std::make_pair(Element::keyName, [this](){ return new Element(this); }),
		std::make_pair(ElementSet::keyName, [this](){ return new ElementSet(this); }),
		std::make_pair(Node::keyName, [this](){ return new Node(this); }),
		std::make_pair(NodeSet::keyName, [this](){ return new NodeSet(this); }),
	};

	for (auto childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = childDef.second();
			child->addParams(token->parameters);
			children.push_back(std::unique_ptr <Keywords::Keyword>(child));
			return child;
		}
		
	if (token->name == keyEndName) {
		return parent;
	}

	if (InpReader::verboseUnknownKeyword)
		std::cout << "Unknown Keyword form Part: " << token->name << std::endl;

	return this;
}


void Keywords::Part::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "Part: Append to model" << std::endl;
	
	//TODO: Add parts to the model.

	for (const auto & child : children)
		child->appendToModel(model);
}
