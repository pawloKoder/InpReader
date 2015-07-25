#ifndef STEP_H
#define STEP_H

#include <string>


class Dynamic;
class Static; // Manual reference : 18.31


/* Manual reference : 18.36 */
class Step {
	std::string name;
	bool nlgeom;

	Dynamic *dynamicAnalisis;
	Static *staticAnalisis;
};


#endif //STEP_H