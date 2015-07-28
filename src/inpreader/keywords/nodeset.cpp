#include <keywords/nodeset.h>

#include "tokens/dataline.h"


const std::string Keywords::NodeSet::keyName = "Nset";


Keywords::NodeSet::NodeSet(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::NodeSet::appendDataLine(const Tokens::DataLine * line)
{
	for (size_t i = 0; i < line->data.size(); ++i)
		if (!line->data[i].empty())
			nodes.insert(std::stod(line->data[i]));

	return this;
}

