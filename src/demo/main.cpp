#include <algorithm>
#include <iostream>
#include <vector>

#include "color.h"
#include "inpreader/model.h"
#include "inpreader/tokenizer.h"
#include "inpreader/parser.h"


Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);


void readerTest() {
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
}


void modelTest() {
	std::string example = "examples/plytka.inp";
	
	std::cout << green << "Model test: " << example << def << std::endl;
	
	InpReader::Model model(Parser::parse(Tokenizer::fromFile(example)));
	
	auto nodes = model.getNodes();
	std::cout << "Number of nodes:" << nodes.size() << std::endl;
	for (auto node : nodes)
		std::cout << node.number << ": " << node.coordinate[0] << ", " << node.coordinate[1] << std::endl;
}


int main(int argc, char **argv) {

	readerTest();
	modelTest();

    return 0;
}
