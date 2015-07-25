#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <string>


/* Manual reference : 2.11 */
class Boundary {
	// Node number or node set label.
	std::string nodeSetLabel;
	int nodeNumber;
	
	// Label specifying the type of boundary condition to be applied 
	std::string boundaryType;
};


#endif //BOUNDARY_H