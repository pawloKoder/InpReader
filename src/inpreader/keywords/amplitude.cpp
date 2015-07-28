#include "keywords/amplitude.h"

#include <string>

#include "tokens/dataline.h"


const std::string Keywords::Amplitude::keyName = "Amplitude";


Keywords::Amplitude::Amplitude(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Amplitude::appendDataLine(const Tokens::DataLine * line)
{
	for (auto parameter : line->data)
		if (!parameter.empty())
			parameters.push_back(std::stod(parameter));

	return this;
}

