#ifndef BASEKEYWORD_H
#define BASEKEYWORD_H

#include <memory>
#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

class BaseKeyword : public Keyword {
public:
	BaseKeyword();
	
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);
	virtual Keywords::Keyword * appendComment(const Tokens::Comment *);

	const std::vector <std::shared_ptr <Keywords::Keyword> > & getChildren() const;
	
	virtual void appendToModel(InpReader::Model *);
private:
	std::vector <std::shared_ptr <Keywords::Keyword> > children;
};

}

#endif //BASEKEYWORD_H