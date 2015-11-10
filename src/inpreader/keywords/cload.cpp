#include <keywords/cload.h>

#include "basic.h"
#include "model.h"
#include "tokens/dataline.h"
#include "settings.h"


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

	loads.push_back(data);

	return this;
}


void Keywords::CLoad::appendToStep(InpReader::Step * step, InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "DSload: Append to model" << std::endl;

	for (auto load : loads) {
		InpReader::CLoad l;
		l.nodeSet = model->getNodeSet(load.nodeSetLabel);
		l.degree = load.deg;
		l.magnitude = load.magnitude;
		step->cloads.push_back(l);
	}
}

