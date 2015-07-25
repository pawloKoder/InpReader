#ifndef KEYWORD_H
#define KEYWORD_H

#include <ostream>
#include <string>
#include <map>

#include "tokens/token.h"


namespace Tokens {

struct Keyword : public Token {
	std::string name;
	
	std::map <std::string, std::string> parameters;
	
	Keyword(std::string line);
	
	virtual void print(std::ostream &) const;
};


std::ostream & operator<< (std::ostream & stream, const Keyword & key);

}

#endif //KEYWORD_H