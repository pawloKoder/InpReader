#ifndef KEYWORDS_NODE_H
#define KEYWORDS_NODE_H

#include <string>
#include <vector>

#include "basic.h"
#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 14.9 */
class Node : public Keyword {
public:
	static const std::string keyName;

	Node(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual void appendToModel(InpReader::Model *);


private:
	std::vector<InpReader::Node> nodes;
};

}

#endif //KEYWORDS_NODE_H