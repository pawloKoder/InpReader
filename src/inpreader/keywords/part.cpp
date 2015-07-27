#include "keywords/part.h"

#include <iostream>
#include <cstdio>

#include "keywords/element.h"
#include "keywords/heading.h"
#include "keywords/node.h"
#include "keywords/material.h"
#include "keywords/preprint.h"
#include "tokens/keyword.h"

#include <functional>
#include <vector>
#include <boost/concept_check.hpp>


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
		std::make_pair(Node::keyName, [this](){ return new Node(this); }),
		std::make_pair(Element::keyName, [this](){ return new Element(this); }),
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

	std::cout << "Unknown Keyword form Part: " << token->name << std::endl;

	return this;
}