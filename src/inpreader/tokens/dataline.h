#ifndef DATALINE_H
#define DATALINE_H

#include <vector>
#include <string>

#include "tokens/token.h"


namespace Tokens {

struct DataLine : public Token {
	std::vector <std::string> data;
	
	DataLine(std::string line);
};

}

#endif //DATALINE_H