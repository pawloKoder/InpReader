#include <keywords/node.h>

#include <iostream>

#include "tokens/dataline.h"


const std::string Keywords::Node::keyName = "Node";


Keywords::Node::Node(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Node::appendDataLine(const Tokens::DataLine * line)
{
	Node::NodeData data;
	std::cout << "Node append DataLine\n";
	if (line->data.size() >= 1)
		data.number = std::stoi(line->data[0]);

	for (int i = 0; i < std::max((int)line->data.size() - 1, 3); ++i)
		data.coordinate[i] = std::stoi(line->data[1 + i]);

	nodes.push_back(data);

	return this;
}

