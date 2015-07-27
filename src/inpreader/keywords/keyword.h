#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>


namespace Tokens {

class Comment;
class DataLine;
class Keyword;

}


namespace Keywords {

class Keyword {
public:
	Keyword(Keyword * parent);

	virtual Keywords::Keyword * appendComment(const Tokens::Comment *);
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

protected:
	Keyword * parent;
};

}

#endif //KEYWORD_H