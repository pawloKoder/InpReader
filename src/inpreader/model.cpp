#include "model.h"

#include <iostream>

#include "keywords/basekeyword.h"
#include "keywords/keyword.h"


InpReader::Model::Model(std::unique_ptr< Keywords::BaseKeyword > root)
{
	for (const auto & child : root->getChildren()) {
		child->appendToModel(this);
	}
}


void InpReader::Model::append(Node node)
{
	nodes[node.number] = node;
}


void InpReader::Model::append(InpReader::Element element)
{
	elements[element.number] = element;
}


void InpReader::Model::append(InpReader::ElementSet eset)
{
	elementSets[eset.name] = eset;
}


void InpReader::Model::append(InpReader::NodeSet nset)
{
	nodeSets[nset.name] = nset;
}


void InpReader::Model::append(InpReader::Step step)
{
	steps.push_back(step);
}


void InpReader::Model::append(InpReader::ElementSurface surface)
{
	surfaces[surface.name] = surface;
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


std::vector< InpReader::Step > InpReader::Model::getSteps()
{
	return steps;
}


InpReader::NodeSet InpReader::Model::getNodeSet(std::string name)
{
	try {
		return nodeSets.at(name);
	} catch (std::out_of_range) {
		std::cerr << "Cannot find nodeset: " << name << std::endl;
		return InpReader::NodeSet();
	}
}


InpReader::ElementSet InpReader::Model::getElementSet(std::string name)
{
	try {
		return elementSets.at(name);
	} catch (std::out_of_range) {
		std::cerr << "Cannot find elementset: " << name << std::endl;
		return InpReader::ElementSet();
	}
}


InpReader::ElementSurface InpReader::Model::getElementSurface(std::string name)
{
	try {
		return surfaces.at(name);
	} catch (std::out_of_range) {
		std::cerr << "Cannot find surface: " << name << std::endl;
		return InpReader::ElementSurface();
	}
}
