#include <algorithm>
#include <iostream>
#include <vector>

#include "color.h"
#include "inpreader/model.h"
#include "inpreader/tokenizer.h"
#include "inpreader/parser.h"


int main(int argc, char **argv) {
	Color::Modifier green(Color::FG_GREEN);
	Color::Modifier def(Color::FG_DEFAULT);
	
	std::vector <std::string> examples = {
		"examples/plytka.inp",
		"examples/ramka.inp",
		"examples/plyta+rama.inp",
	};
	
	for (auto example : examples) {
		std::cout << green << "File " << example << def << std::endl;
		
		auto tokens = Tokenizer::fromFile(example);
		
		auto rootKeyword = Parser::parse(tokens);
		
		InpReader::Model m(rootKeyword);
	}
	
    return 0;
}
