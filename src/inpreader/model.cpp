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
