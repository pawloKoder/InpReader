#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "basic.h"


namespace Keywords {
	class BaseKeyword;
	class Node;
}


namespace InpReader {

/* Represents a FEM model */
class Model {
public:
	Model(std::shared_ptr <Keywords::BaseKeyword>);

	void append(InpReader::Element);
	void append(InpReader::ElementSet);
	void append(InpReader::Node);
	void append(InpReader::NodeSet);
	void append(InpReader::Step);
	void append(InpReader::ElementSurface);
	
	std::vector<InpReader::Node> getNodes();
	std::vector<InpReader::Element> getElements();
	std::vector<InpReader::Step> getSteps();

	InpReader::NodeSet getNodeSet(std::string name);
	InpReader::ElementSet getElementSet(std::string name);

private:
	std::map<int, InpReader::Element> elements;
	std::map<std::string, InpReader::ElementSet> elementSets;
	std::map<int, InpReader::Node> nodes;
	std::map<std::string, InpReader::NodeSet> nodeSets;
	std::vector<InpReader::Step> steps;
	std::map<std::string, InpReader::ElementSurface> surfaces;
};

}

#endif //MODEL_H