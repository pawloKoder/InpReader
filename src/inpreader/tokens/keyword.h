#ifndef TOKENS_KEYWORD_H
#define TOKENS_KEYWORD_H

#include <ostream>
#include <string>
#include <map>

#include "tokens/token.h"


namespace Keywords {

class Keyword;

}


namespace Tokens {

struct Keyword : public Token {
	std::string name;
	
	std::map <std::string, std::string> parameters;
	
	Keyword(std::string line);
	
	virtual Keywords::Keyword * appendToKeyword(Keywords::Keyword *);
	virtual void print(std::ostream &) const;
};


std::ostream & operator<< (std::ostream & stream, const Keyword & key);

}

#endif //TOKENS_KEYWORD_H