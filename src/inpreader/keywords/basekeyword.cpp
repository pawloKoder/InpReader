#include "keywords/basekeyword.h"
#include "heading.h"

#include <iostream>
#include <cstdio>

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


template <class T>
std::pair <std::string, std::function<Keywords::Keyword*()> > createDef(Keywords::Keyword* base) {
	return std::make_pair(T::keyName, [&](){ return new T(base); });
}


Keywords::Keyword * Keywords::BaseKeyword::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<Keyword*()> > > possibleChildren = {
		std::make_pair(Heading::keyName, [this](){ return new Heading(this); }),
		std::make_pair(Node::keyName, [this](){ return new Node(this); })
		//createDef<Node>(this)
	};
	std::cout << "Base Append Keyword " << token->name << std::endl;
	for (auto childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = std::shared_ptr <Keywords::Keyword>(childDef.second());
			children.push_back(child);
			return child.get();
		}
	return this;
}