#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>


class Density;
class Elastic;
class Plastic;


/* Manual reference : 13.8 */
class Material {
	std::string name;
	
	Density *density;
	Elastic *elastic;
	Plastic *plastic;
};


#endif //MATERIAL_H