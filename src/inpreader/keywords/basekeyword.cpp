#include "keywords/basekeyword.h"
#include "heading.h"

#include <iostream>
#include <cstdio>

#include "keywords/element.h"
#include "keywords/heading.h"
#include "keywords/node.h"
#include "tokens/keyword.h"

#include <functional>
#include <vector>
#include <boost/concept_check.hpp>


Keywords::BaseKeyword::BaseKeyword():
	Keyword(this)
{}


Keywords::Keyword* Keywords::BaseKeyword::appendComment(const Tokens::Comment*)
{
	//std::cout << "Append Comment\n";
	return this;
}


Keywords::Keyword * Keywords::BaseKeyword::appendDataLine(const Tokens::DataLine*)
{
	//std::cout << "Append DataLine\n";
	return this;
}


Keywords::Keyword * Keywords::BaseKeyword::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<Keyword*()> > > possibleChildren = {
		std::make_pair(Heading::keyName, [this](){ return new Heading(this); }),
		std::make_pair(Node::keyName, [this](){ return new Node(this); }),
		std::make_pair(Element::keyName, [this](){ return new Element(this); })
	};

	for (auto childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = std::shared_ptr <Keywords::Keyword>(childDef.second());
			children.push_back(child);
			return child.get();
		}

	std::cout << "Unknown Keyword form Base: " << token->name << std::endl;

	return this;
}