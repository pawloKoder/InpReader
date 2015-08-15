#ifndef KEYWORDS_ELEMENTSET_H
#define KEYWORDS_ELEMENTSET_H

#include <set>
#include <string>

#include "basic.h"
#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 5.12 */
class ElementSet : public Keyword {
public:
	static const std::string keyName;

	ElementSet(Keyword * parent);
    
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

	virtual void appendToModel(InpReader::Model*);
	virtual void addParams(const std::map< std::string, std::string >&);

private:
	InpReader::ElementSet eset;
	bool generate;
};

}

#endif //KEYWORDS_ELEMENTSET_H