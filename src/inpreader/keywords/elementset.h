#ifndef KEYWORDS_ELEMENTSET_H
#define KEYWORDS_ELEMENTSET_H

#include <set>
#include <string>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 5.13 */
class ElementSet : public Keyword {
public:
	static const std::string keyName;

	ElementSet(Keyword * parent);
    
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	std::string name;
	std::set<int> elements;
};

}

#endif //KEYWORDS_ELEMENTSET_H