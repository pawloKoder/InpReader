#ifndef DLOAD_H
#define DLOAD_H

#include <string>


/* Manual reference : 4.30 */
class DLoad {
	
	// Element number or element set label.
	std::string nodeSetLabel;
	int nodeNumber;
	
	// Distributed load type label
	std::string loadType;
	
	// Reference magnitude for load.
	double magnitude;  
};


#endif //DLOAD_H