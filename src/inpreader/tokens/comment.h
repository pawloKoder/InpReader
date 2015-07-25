#ifndef COMMENT_H
#define COMMENT_H

#include <string>

#include "tokens/token.h"


namespace Tokens {

struct Comment : public Token {
	std::string content;
	
	Comment(std::string line);
};

}

#endif //COMMENT_H