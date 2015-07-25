#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>
#include <map>

#include "tokens/token.h"


namespace Tokens {

struct Keyword : public Token {
	std::string name;
	
	std::map <std::string, std::string> parameters;
	
	Keyword(std::string line);
};

}

#endif //KEYWORD_H