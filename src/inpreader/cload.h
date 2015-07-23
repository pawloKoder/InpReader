#ifndef CLOAD_H
#define CLOAD_H

#include <string>


/* Manual reference : 3.21 */
class Cload {
	// Node number or node set label.
	std::string nodeSetLabel;
	int nodeNumber;
	
	// Degree of freedom.
	int deg;
	
	// Reference magnitude for load.
	double magnitude;
};


#endif //CLOAD_H