#ifndef READER_BASIC_H
#define READER_BASIC_H

#include <vector>
#include <string>


namespace InpReader {

struct Node {
	int number;
	double coordinate[3];
	double dirCosine[3];
};

struct NodeSet {
	std::string name;
	std::vector<int> nodes;
};

struct Element {
	int number;
	std::vector<int> node_numbers;
	std::string type;
};

struct ElementSet {
	std::string name;
	std::vector<int> elements;
};

struct ElementSurface {
	std::string name;
	std::vector<ElementSet> eset;
	std::vector<std::string> face;
};

struct DSLoad {
	ElementSurface surface;
	std::string type;
	double magnitude;
	double traction_vector[3];
};

struct CLoad {
	NodeSet nodeSet;
	int degree;
	double magnitude;
};


struct Boundary {
	//TODO: Change type into enum
	std::string type;
	NodeSet set;
};

struct Step {
	std::string name;
	std::vector<Boundary> boundaries;
	std::vector<DSLoad> dsloads;
	std::vector<CLoad> cloads;
};

}

#endif