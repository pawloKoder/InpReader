#include "tokenizer.h"

#include <fstream>
#include <string>
#include <iostream>

#include "tokens/token.h"


std::vector <std::unique_ptr <Tokens::Token> > Tokenizer::fromFile(std::string filename) {
	std::ifstream input(filename);

	std::vector <std::unique_ptr <Tokens::Token> > result;
	int lineNum = 1;
	while (input.good()) {
		std::string line;
		std::getline(input, line);
		auto token = Tokens::Token::fromString(line);
		token->file = filename;
		token->lineNum = lineNum++;
		result.push_back(std::move(token));
	}

	return result;
}
