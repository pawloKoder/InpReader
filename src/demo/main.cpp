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
		
		auto rootKeyword = Parser::parse(std::move(tokens));
		
		InpReader::Model m(std::move(rootKeyword));
	}
}


void modelTest() {
	std::string example = "examples/plytka.inp";
	
	std::cout << green << "Model test: " << example << def << std::endl;
	
	InpReader::Model model(std::move(Parser::parse(Tokenizer::fromFile(example))));
	
	auto nodes = model.getNodes();
	std::cout << "Number of nodes:" << nodes.size() << std::endl;
	/*for (auto node : nodes)
		std::cout << node.number << ": " << node.coordinate[0] << ", " << node.coordinate[1] << std::endl;*/
	
	
	auto elements = model.getElements();
	std::cout << "Number of elements:" << elements.size() << std::endl;
	/*for (auto element : elements) {
		std::cout << element.number << "(" << element.type << "): ";
		for (auto node : element.node_numbers)
			std::cout << node << ", ";
		std::cout << std::endl;
	}*/
	
	auto steps = model.getSteps();
	std::cout << "Number of steps:" << steps.size() << std::endl;
	for (auto step : steps) {
		std::cout << "Step name: " << step.name << std::endl;
		for (auto boundary : step.boundaries) {
			std::cout << "Boundary " << boundary.type << ": ";
			for (auto node : boundary.set.nodes)
				std::cout << node << ", ";
			std::cout << std::endl;
		}
		for (auto load : step.dsloads) {
			std::cout << "Load " << load.type << "(" << load.magnitude << ") "
				<< load.surface.name << ":" << std::endl;
			for (unsigned i = 0; i < load.surface.eset.size(); ++i) {
				std::cout << load.surface.eset[i].name << "(" << load.surface.face[i] << "): ";
				for (auto element : load.surface.eset[i].elements) {
					std::cout << element << ", ";
				}
				std::cout << std::endl;
			}
		}
	}
	
}


int main(int argc, char **argv) {

	readerTest();
	modelTest();

    return 0;
}
