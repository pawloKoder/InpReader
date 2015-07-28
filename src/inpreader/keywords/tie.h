#ifndef KEYWORDS_TIE_H
#define KEYWORDS_TIE_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {
	
/* Manual reference : 3.21 */
class Tie : public Keyword {
public:
	static const std::string keyName;

	Tie(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	std::vector <std::pair <std::string, std::string>> ties;
};

}

#endif //KEYWORDS_TIE_H