#include <keywords/tie.h>

#include "tokens/dataline.h"


const std::string Keywords::Tie::keyName = "Tie";


Keywords::Tie::Tie(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Tie::appendDataLine(const Tokens::DataLine * line)
{
	if (line->data.size() >= 2)
		ties.push_back(std::make_pair(line->data[0], line->data[1]));

	return this;
}

