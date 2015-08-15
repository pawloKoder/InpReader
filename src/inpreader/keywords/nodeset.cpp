#include <keywords/nodeset.h>

#include "model.h"
#include "settings.h"
#include "tokens/dataline.h"


const std::string Keywords::NodeSet::keyName = "Nset";


Keywords::NodeSet::NodeSet(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::NodeSet::appendDataLine(const Tokens::DataLine * line)
{
	for (size_t i = 0; i < line->data.size(); ++i)
		if (!line->data[i].empty())
			nset.nodes.push_back(std::stod(line->data[i]));

	return this;
}

void Keywords::NodeSet::appendToModel(InpReader::Model * model)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "NodeSet: Append to model: " << nset.name << std::endl;
	
	model->append(nset);
}


void Keywords::NodeSet::addParams(const std::map< std::string, std::string >& params)
{
	auto t = params.find("nset");
	if (t != params.end())
		nset.name = t->second;
}
