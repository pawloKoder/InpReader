#include <keywords/elementset.h>

#include "model.h"
#include "settings.h"
#include "tokens/dataline.h"


const std::string Keywords::ElementSet::keyName = "Elset";


Keywords::ElementSet::ElementSet(Keywords::Keyword* parent): 
	Keyword(parent),
	generate(false)
{}


Keywords::Keyword* Keywords::ElementSet::appendDataLine(const Tokens::DataLine * line)
{
	if (!generate)
		for (size_t i = 0; i < line->data.size(); ++i)
			eset.elements.push_back(std::stoi(line->data[i]));
	else {
		int begin = std::stoi(line->data[0]);
		int end = std::stoi(line->data[1]);
		int increment = std::stoi(line->data[2]);
		
		for (int i = begin; i <= end; i += increment)
			eset.elements.push_back(i);
	}

	return this;
}


void Keywords::ElementSet::addParams(const std::map< std::string, std::string >& params)
{
	auto t = params.find("elset");
	if (t != params.end())
		eset.name = t->second;
	
	auto g = params.find("generate");
	if (g != params.end())
		generate = true;
}


void Keywords::ElementSet::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "ElementSet: Append to model: " << eset.name << std::endl;
	
	model->append(eset);
}

