#ifndef KEYWORDS_NODESET_H
#define KEYWORDS_NODESET_H

#include <set>
#include <string>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 14.17 */
class NodeSet : public Keyword {
public:
	static const std::string keyName;

	NodeSet(Keyword * parent);
    
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	std::string name;
	std::set<int> nodes;
};

}

#endif //KEYWORDS_NODESET_H