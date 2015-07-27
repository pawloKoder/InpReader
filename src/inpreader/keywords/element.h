#ifndef KEYWORDS_ELEMENT_H
#define KEYWORDS_ELEMENT_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 5.7 */
class Element : public Keyword {
public:
	static const std::string keyName;

	Element(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

	struct ElementData {
		int number;
		std::vector<int> node_numbers;
	};

private:
	std::string type;
	std::vector<ElementData> elements;
};

}

#endif //KEYWORDS_ELEMENT_H