#include "keywords/elastic.h"

#include "tokens/dataline.h"


const std::string Keywords::Elastic::keyName = "Elastic";


Keywords::Elastic::Elastic(Keywords::Keyword* parent): MaterialProp(parent)
{}


Keywords::Keyword* Keywords::Elastic::appendDataLine(const Tokens::DataLine * line)
{
	for (auto module : line->data)
		modules.push_back(std::stod(module));

	return this;
}

void Keywords::Elastic::appendToMaterial(Keywords::Material * mat)
{
	mat->appendElastic(this);
}

