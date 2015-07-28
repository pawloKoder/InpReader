#include <keywords/elementset.h>

#include "tokens/dataline.h"


const std::string Keywords::ElementSet::keyName = "Elset";


Keywords::ElementSet::ElementSet(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::ElementSet::appendDataLine(const Tokens::DataLine * line)
{
	for (size_t i = 0; i < line->data.size(); ++i)
		elements.insert(std::stod(line->data[i]));

	return this;
}

