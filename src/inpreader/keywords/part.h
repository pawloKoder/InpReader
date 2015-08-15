#ifndef KEYWORDS_PART_H
#define KEYWORDS_PART_H

#include <memory>
#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 16.4 */
class Part : public Keyword {
public:
	static const std::string keyName;
	static const std::string keyEndName;

	Part(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

    virtual void appendToModel(InpReader::Model*);

private:
	std::vector <std::shared_ptr <Keywords::Keyword> > children;
};

}

#endif //KEYWORDS_PART_H