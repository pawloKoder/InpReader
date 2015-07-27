#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <ostream>

#include "tokens/token.h"


namespace Keywords {

class Keyword;

}


namespace Tokens {

struct Comment : public Token {
	std::string content;

	Comment(std::string line);

	virtual Keywords::Keyword * appendToKeyword(Keywords::Keyword *);
	virtual void print(std::ostream &) const;
};


std::ostream & operator<< (std::ostream & stream, const Tokens::Comment & comment);

}

#endif //COMMENT_H