#ifndef KEYWORDS_ELEMENT_H
#define KEYWORDS_ELEMENT_H

#include <string>
#include <vector>

#include "basic.h"
#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 5.7 */
class Element : public Keyword {
public:
	static const std::string keyName;

	Element(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

    virtual void appendToModel(InpReader::Model*);
private:
	std::string type;
	std::vector<InpReader::Element> elements;
};

}

#endif //KEYWORDS_ELEMENT_H