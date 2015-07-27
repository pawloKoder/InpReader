#ifndef DATALINE_H
#define DATALINE_H

#include <iostream>
#include <vector>
#include <string>

#include "tokens/token.h"


namespace Keywords {

class Keyword;

}


namespace Tokens {

struct DataLine : public Token {
	std::vector <std::string> data;
	
	DataLine(std::string line);
	
	virtual Keywords::Keyword * appendToKeyword(Keywords::Keyword *);
	virtual void print(std::ostream &) const;
};


std::ostream & operator<< (std::ostream & stream, const Tokens::DataLine & data);

}

#endif //DATALINE_H