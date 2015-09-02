#include "keywords/basekeyword.h"
#include "heading.h"

#include <iostream>
#include <cstdio>

#include "keywords/amplitude.h"
#include "keywords/assembly.h"
#include "keywords/boundary.h"
#include "keywords/element.h"
#include "keywords/heading.h"
#include "keywords/node.h"
#include "keywords/material.h"
#include "keywords/part.h"
#include "keywords/preprint.h"
#include "keywords/step.h"
#include "settings.h"
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
		std::make_pair(Amplitude::keyName, [this](){ return new Amplitude(this); }),
		std::make_pair(Assembly::keyName, [this](){ return new Assembly(this); }),
		std::make_pair(Boundary::keyName, [this](){ return new Boundary(this); }),
		std::make_pair(Heading::keyName, [this](){ return new Heading(this); }),
		std::make_pair(Node::keyName, [this](){ return new Node(this); }),
		std::make_pair(Element::keyName, [this](){ return new Element(this); }),
		std::make_pair(Material::keyName, [this](){ return new Material(this); }),
		std::make_pair(Part::keyName, [this](){ return new Part(this); }),
		std::make_pair(Preprint::keyName, [this](){ return new Preprint(this); }),
		std::make_pair(Step::keyName, [this](){ return new Step(this); })
	};

	for (auto childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = childDef.second();
			child->addParams(token->parameters);
			children.push_back(std::unique_ptr <Keywords::Keyword> (child));
			return child;
		}

	std::cout << "Unknown Keyword form Base: " << token->name << std::endl;

	return this;
}


const std::vector< std::unique_ptr< Keywords::Keyword > >& Keywords::BaseKeyword::getChildren() const
{
	return children;
}

void Keywords::BaseKeyword::appendToModel(InpReader::Model* model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "BaseKeyword: Append to model" << std::endl;

	for (const auto & child : children)
		child->appendToModel(model);
}

