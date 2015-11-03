#include <keywords/nodeset.h>

#include "model.h"
#include "settings.h"
#include "tokens/dataline.h"


const std::string Keywords::NodeSet::keyName = "Nset";


Keywords::NodeSet::NodeSet(Keywords::Keyword* parent): Keyword(parent),
	nodeGeneration(false)
{}


Keywords::Keyword* Keywords::NodeSet::appendDataLine(const Tokens::DataLine * line)
{
	if (!nodeGeneration) {
		for (size_t i = 0; i < line->data.size(); ++i)
			if (!line->data[i].empty())
				nset.nodes.push_back(std::stoi(line->data[i]));
	} else {
		if (line->data.size() >= 3) {
			int n1 = std::stod(line->data[0]);
			int n2 = std::stod(line->data[1]);
			int increment = std::stod(line->data[2]);
			for (int i = n1; i <= n2; i += increment)
				nset.nodes.push_back(i);
		}
	}

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
	
	auto g = params.find("generate");
	if (g != params.end())
		nodeGeneration = true;
}
