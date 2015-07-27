#ifndef KEYWORDS_HEADING_H
#define KEYWORDS_HEADING_H

#include <string>

#include "keywords/keyword.h"


namespace Keywords {

class Heading : public Keyword {
public:
	static const std::string keyName;
	
	Heading(Keyword * parent);

	virtual Keywords::Keyword * appendComment(const Tokens::Comment*);
private:
	std::string content;
};

}

#endif //KEYWORDS_HEADING_H