#ifndef KEYWORDS_NODE_H
#define KEYWORDS_NODE_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 14.9 */
class Node : public Keyword {
public:
	static const std::string keyName;

	Node(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

	struct NodeData {
		int number;
		double coordinate[3];
		double dirCosine[3];
	};

private:
	std::vector<NodeData> nodes;
};

}

#endif //KEYWORDS_NODE_H