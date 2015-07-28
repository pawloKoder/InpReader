#include "keywords/dynamic.h"

#include <string>

#include "tokens/dataline.h"


const std::string Keywords::Dynamic::keyName = "Dynamic";


Keywords::Dynamic::Dynamic(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Dynamic::appendDataLine(const Tokens::DataLine * line)
{
	initialIncrement = 0.0;
	timePeriod = 1.0;
	minIncrement = 0.0;
	maxIncrement = 0.0;

	if (line->data.size() >= 1)
		initialIncrement = std::stod(line->data[0]);

	if (line->data.size() >= 2)
		timePeriod = std::stod(line->data[1]);

	if (line->data.size() >= 3)
		minIncrement = std::stod(line->data[2]);

	if (line->data.size() >= 4)
		maxIncrement = std::stod(line->data[3]);

	return this;
}

