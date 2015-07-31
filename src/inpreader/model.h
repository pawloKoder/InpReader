#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <memory>
#include <string>

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

	void appendNode(InpReader::Node);
	
	
private:
	std::map<int, InpReader::Node> nodes;
};

}

#endif //MODEL_H