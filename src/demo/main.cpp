#include <iostream>

#include "inpreader/tokenizer.h"
#include "inpreader/parser.h"


int main(int argc, char **argv) {
	
	auto tokens = Tokenizer::fromFile("examples/plytka.inp");
	
	/*for (auto token : tokens) {
		token->print(std::cout);
		std::cout << std::endl;
	}*/
	
	Parser::parse(tokens);
	
    return 0;
}
