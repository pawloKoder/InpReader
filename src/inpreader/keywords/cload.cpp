#include <keywords/cload.h>

#include "tokens/dataline.h"


const std::string Keywords::CLoad::keyName = "Cload";


Keywords::CLoad::CLoad(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::CLoad::appendDataLine(const Tokens::DataLine * line)
{
	CLoad::ConcentratedLoadData data;

	if (line->data.size() >= 1)
		data.nodeSetLabel = line->data[0];
	if (line->data.size() >= 2)
		data.deg = std::stoi(line->data[1]);
	if (line->data.size() >= 3)
		data.magnitude = std::stod(line->data[2]);

	load.push_back(data);

	return this;
}

