#include <keywords/surface.h>

#include "tokens/dataline.h"


const std::string Keywords::Surface::keyName = "Surface";


Keywords::Surface::Surface(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Surface::appendDataLine(const Tokens::DataLine * line)
{
	if (line->data.size() >= 2) {
		elementSet.push_back(line->data[0]);
		face.push_back(line->data[1]);
	}

	return this;
}

