#ifndef KEYWORDS_ASSEMBLY_H
#define KEYWORDS_ASSEMBLY_H

#include <memory>
#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 1.14 */
class Assembly : public Keyword {
public:
	static const std::string keyName;
	static const std::string keyEndName;

    Assembly(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

private:
	std::string name;
	std::vector <std::shared_ptr <Keywords::Keyword> > children;
};

}

#endif //KEYWORDS_ASSEMBLY_H