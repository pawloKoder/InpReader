#include "keywords/boundary.h"

#include "tokens/dataline.h"


const std::string Keywords::Boundary::keyName = "Boundary";


Keywords::Boundary::Boundary(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Boundary::appendDataLine(const Tokens::DataLine * line)
{
	if (line->data.size() >= 2) {
		nodeSetLabel.push_back(line->data[0]);
		boundaryType.push_back(line->data[1]);
	}

	return this;
}

