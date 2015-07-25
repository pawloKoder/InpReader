#ifndef NODESET_H
#define NODESET_H

#include <set>
#include <string>


class Node;



/* Manual reference : 14.17 */
class NodeSet {
	std::string name;
	std::set<Node*> nodes;
};


#endif //NODESET_H