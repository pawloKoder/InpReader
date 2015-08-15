#include "keywords/element.h"

#include "model.h"
#include "settings.h"
#include "tokens/dataline.h"


const std::string Keywords::Element::keyName = "Element";


Keywords::Element::Element(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Element::appendDataLine(const Tokens::DataLine * line)
{
	InpReader::Element data;
	
	if (line->data.size() >= 1)
		data.number = std::stoi(line->data[0]);

	for (size_t i = 1; i < line->data.size(); ++i)
		data.node_numbers.push_back(std::stoi(line->data[i]));

	elements.push_back(data);

	return this;
}

void Keywords::Element::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "Element: Append to model" << std::endl;
	
	for (auto element : elements)
		model->appendElement(element);
}
