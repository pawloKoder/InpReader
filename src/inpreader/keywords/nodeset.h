#ifndef KEYWORDS_NODESET_H
#define KEYWORDS_NODESET_H

#include <set>
#include <string>

#include "basic.h"
#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 14.17 */
class NodeSet : public Keyword {
public:
	static const std::string keyName;

	NodeSet(Keyword * parent);
    
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

    virtual void appendToModel(InpReader::Model*);
	
    virtual void addParams(const std::map< std::string, std::string >&);

private:
	InpReader::NodeSet nset;
	bool nodeGeneration;
};

}

#endif //KEYWORDS_NODESET_H