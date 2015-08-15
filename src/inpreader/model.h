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

	void append(InpReader::Node);
	void append(InpReader::Element);
	void append(InpReader::NodeSet);
	
	std::vector<InpReader::Node> getNodes();
	std::vector<InpReader::Element> getElements();

private:
	std::map<int, InpReader::Element> elements;
	std::map<int, InpReader::Node> nodes;
	std::map<std::string, InpReader::NodeSet> nodeSets;
};

}

#endif //MODEL_H