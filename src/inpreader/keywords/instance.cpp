#include "keywords/instance.h"

#include <functional>
#include <vector>
#include <iostream>

#include "tokens/keyword.h"


const std::string Keywords::Instance::keyName = "Instance";
const std::string Keywords::Instance::keyEndName = "End Instance";


Keywords::Instance::Instance(Keyword* parent) : Keyword(parent)
{}


Keywords::Keyword * Keywords::Instance::appendDataLine(const Tokens::DataLine*)
{
	return this;
}


Keywords::Keyword * Keywords::Instance::appendKeyword(const Tokens::Keyword * token)
{
	std::vector <std::pair <std::string, std::function<Keyword*()> > > possibleChildren = {
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

	std::cout << "Unknown Keyword form Instance: " << token->name << std::endl;

	return this;
}