#ifndef MATERIAL_H
#define MATERIAL_H

#include <memory>
#include <string>

#include "keywords/keyword.h"


namespace Keywords {

class Density;
class Elastic;


/* Manual reference : 13.8 */
class Material : public Keyword {
public:
	static const std::string keyName;
	
	Material(Keyword * parent);

	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

	void appendDensity(Density *);
	void appendElastic(Elastic *);
private:
	std::string name;
	
	std::unique_ptr <Keywords::Density> density;
	std::unique_ptr <Keywords::Elastic> elastic;
};


class MaterialProp : public Keyword {
public:
	MaterialProp(Keyword* parent);

	virtual void appendToMaterial(Material *) = 0;
};

}

#endif //MATERIAL_H