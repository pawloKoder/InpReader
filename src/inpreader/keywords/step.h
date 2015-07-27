#ifndef KEYWORDS_STEP_H
#define KEYWORDS_STEP_H

#include <memory>
#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 18.36 */
class Step : public Keyword {
public:
	static const std::string keyName;
	static const std::string keyEndName;

    Step(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

private:
	std::string name;
	std::vector <std::shared_ptr <Keywords::Keyword> > children;
};

}

#endif //KEYWORDS_STEP_H