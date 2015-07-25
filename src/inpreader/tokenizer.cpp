#include "tokenizer.h"

#include <fstream>
#include <string>

#include "tokens/token.h"


std::vector <std::shared_ptr <Tokens::Token> > Tokenizer::fromFile(std::string filename) {
	std::ifstream input(filename);
	
	std::vector <std::shared_ptr <Tokens::Token> > result;
	while (input.good()) {
		std::string line;
		std::getline(input, line);
		result.push_back(Tokens::Token::fromString(line));
	}
	
	return result;
}