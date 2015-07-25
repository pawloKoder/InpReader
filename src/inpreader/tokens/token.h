#ifndef TOKEN_H
#define TOKEN_H


#include <memory>
#include <string>


namespace Tokens {

struct Token {
	static std::shared_ptr <Token> fromString(std::string);
	
	virtual void print(std::ostream &) const;
};


std::ostream & operator<< (std::ostream & stream, const Tokens::Token &);

}

#endif //TOKEN_H