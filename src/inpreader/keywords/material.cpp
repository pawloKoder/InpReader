#include <keywords/material.h>

#include <vector>

#include "keywords/density.h"
#include "keywords/elastic.h"
#include "tokens/keyword.h"


const std::string Keywords::Material::keyName = "Material";


Keywords::Material::Material(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword * Keywords::Material::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<MaterialProp*()> > > possibleChildren = {
		std::make_pair(Density::keyName, [this](){ return new Density(this); }),
		std::make_pair(Elastic::keyName, [this](){ return new Elastic(this); })
	};

	for (auto childDef : possibleChildren)
		if (token->name == childDef.first) {
			auto child = childDef.second();
			child->appendToMaterial(this);
			return child;
		}

	return parent->appendKeyword(token);
}


void Keywords::Material::appendDensity(Density * dens) {
	density.reset(dens);
}


void Keywords::Material::appendElastic(Elastic * ela) {
	elastic.reset(ela);
}


Keywords::MaterialProp::MaterialProp(Keywords::Keyword* parent): Keyword(parent)
{}