#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <vector>


/* Manual reference : 5.7 */
class Element {
	std::string type;
	int number;
	std::vector<int> node_numbers;
};


#endif //ELEMENT_H