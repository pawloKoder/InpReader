#ifndef ELEMENTSET_H
#define ELEMENTSET_H

#include <set>
#include <string>


class Element;


/* Manual reference : 5.13 */
class ElementSet {
	std::string name;
	std::set<Element*> elements;
};


#endif //ELEMENTSET_H