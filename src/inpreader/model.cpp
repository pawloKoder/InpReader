#include "model.h"

#include "keywords/basekeyword.h"
#include "keywords/keyword.h"


InpReader::Model::Model(std::shared_ptr< Keywords::BaseKeyword > root)
{
	for (auto child : root->getChildren()) {
		child->appendToModel(this);
	}
}


void InpReader::Model::appendNode(Node node)
{
	nodes[node.number] = node;
}


void InpReader::Model::appendElement(InpReader::Element element)
{
	elements[element.number] = element;
}


std::vector <InpReader::Node> InpReader::Model::getNodes()
{
	std::vector <InpReader::Node> result;
	
	for (auto i : nodes)
		result.push_back(i.second);
	
	return result;
}


std::vector <InpReader::Element> InpReader::Model::getElements()
{
	std::vector <InpReader::Element> result;
	
	for (auto i : elements)
		result.push_back(i.second);
	
	return result;
}