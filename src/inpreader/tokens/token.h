#ifndef TOKEN_H
#define TOKEN_H

#include <memory>
#include <string>


namespace Keywords {

class Keyword;

}


namespace Tokens {

struct Token {
	static std::shared_ptr <Token> fromString(std::string);
	
	virtual Keywords::Keyword * appendToKeyword(Keywords::Keyword *) = 0;
	
	virtual void print(std::ostream &) const;
	
	std::string identifier();

	int lineNum;
	std::string file;
};


std::ostream & operator<< (std::ostream & stream, const Tokens::Token &);

}

#endif //TOKEN_H