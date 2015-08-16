#include <keywords/surface.h>

#include "basic.h"
#include "model.h"
#include "settings.h"
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


void Keywords::Surface::addParams(const std::map< std::string, std::string >& params)
{
	auto t = params.find("type");
	if (t != params.end())
		type = t->second;
	
	auto n = params.find("name");
	if (n != params.end())
		name = n->second;
}


void Keywords::Surface::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "Surface: Append to model: " << name << std::endl;

	if (type == "ELEMENT") {
		InpReader::ElementSurface surface;
		surface.name = name;
		for (unsigned i = 0; i < elementSet.size(); ++i) {
			surface.eset.push_back(model->getElementSet(elementSet[i]));
			surface.face.push_back(face[i]);
		}

		model->append(surface);
	}
}

