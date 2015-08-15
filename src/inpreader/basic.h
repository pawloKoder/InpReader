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

struct Element {
	int number;
	std::vector<int> node_numbers;
	std::string type;
};

}

#endif