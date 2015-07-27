#include "keywords/density.h"

#include "tokens/dataline.h"


const std::string Keywords::Density::keyName = "Density";


Keywords::Density::Density(Keywords::Keyword* parent): MaterialProp(parent)
{}


Keywords::Keyword* Keywords::Density::appendDataLine(const Tokens::DataLine * line)
{
	if (line->data.size() > 0)
		value = std::stod(line->data[0]);

	return this;
}

void Keywords::Density::appendToMaterial(Keywords::Material * mat)
{
	mat->appendDensity(this);
}

