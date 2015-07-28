#include <keywords/dsload.h>

#include "tokens/dataline.h"


const std::string Keywords::DSLoad::keyName = "Dsload";


Keywords::DSLoad::DSLoad(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::DSLoad::appendDataLine(const Tokens::DataLine * line)
{
	DSLoad::DistributedSurfaceData data;

	if (line->data.size() >= 1)
		data.name = line->data[0];
	if (line->data.size() >= 2)
		data.type = line->data[1];
	if (line->data.size() >= 3)
		data.magnitude = std::stod(line->data[2]);

	load.push_back(data);

	return this;
}

