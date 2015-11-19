#include <keywords/dsload.h>

#include "model.h"
#include "settings.h"
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
	for (int i = 0; i < 3; ++i)
		if ((int)line->data.size() >= 4 + i)
			data.traction_vector[i] = std::stod(line->data[3 + i]);

	loads.push_back(data);

	return this;
}


void Keywords::DSLoad::appendToStep(InpReader::Step * step, InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "DSload: Append to model" << std::endl;

	for (auto load : loads) {
		InpReader::DSLoad l;
		l.surface = model->getElementSurface(load.name);
		l.type = load.type;
		l.magnitude = load.magnitude;
		for (int i = 0; i < 3; ++i)
			l.traction_vector[i] = load.traction_vector[i];
		step->dsloads.push_back(l);
	}
}


