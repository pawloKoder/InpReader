#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "basic.h"


namespace Keywords {
	class BaseKeyword;
	class Node;
}


namespace InpReader {

/* Represents a FEM model */
class Model {
public:
	/// Creates an empty model.
	Model() = default;
	
	/// Creates a model basing on tree of keywords.
	Model(std::unique_ptr <Keywords::BaseKeyword>);

	/// Appends an element to the model.
	void append(InpReader::Element);

	/// Appends a set of elements to the model.
	void append(InpReader::ElementSet);

	/// Appends a node to the model.
	void append(InpReader::Node);

	/// Appends a set of nodes to the model.
	void append(InpReader::NodeSet);

	/// Appends a computation step to the model.
	void append(InpReader::Step);

	/// Appends a surface to the model.
	void append(InpReader::ElementSurface);

	/// Get all nodes of the model.
	std::vector<InpReader::Node> getNodes();

	/// Get all elemens of the model.
	std::vector<InpReader::Element> getElements();

	/// Get computation steps.
	/** Detailed description can be found in inp documentatnion 18.36 */
	std::vector<InpReader::Step> getSteps();

	/// Get a set of nodes basing on its name
	/**
	 * \param name identifier of the set of nodes.
	 */
	InpReader::NodeSet getNodeSet(std::string name);

	/// Get a set of elements basing on its name
	/**
	 * \param name identifier of the set of elements.
	 */
	InpReader::ElementSet getElementSet(std::string name);

	/// Get a surface basing on its name
	/**
	 * \param name identifier of the surface.
	 */
	InpReader::ElementSurface getElementSurface(std::string name);

private:
	std::map<int, InpReader::Element> elements;
	std::map<std::string, InpReader::ElementSet> elementSets;
	std::map<int, InpReader::Node> nodes;
	std::map<std::string, InpReader::NodeSet> nodeSets;
	std::vector<InpReader::Step> steps;
	std::map<std::string, InpReader::ElementSurface> surfaces;
};

}

#endif //MODEL_H