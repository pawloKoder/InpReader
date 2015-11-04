#ifndef KEYWORDS_INSTANCE_H
#define KEYWORDS_INSTANCE_H

#include <memory>
#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 9.19 */
class Instance : public Keyword {
public:
	static const std::string keyName;
	static const std::string keyEndName;

    Instance(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

	virtual void appendToModel(InpReader::Model*);

private:
	std::string name;
	std::vector <std::unique_ptr <Keywords::Keyword> > children;
};

}

#endif //KEYWORDS_INSTANCE_H