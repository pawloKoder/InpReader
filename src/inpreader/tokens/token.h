#ifndef TOKEN_H
#define TOKEN_H


#include <memory>
#include <string>


namespace Tokens {

struct Token {
	static std::shared_ptr <Token> fromString(std::string);
};

}

#endif //TOKEN_H