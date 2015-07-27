#ifndef KEYWORDS_DENSITY_H
#define KEYWORDS_DENSITY_H

#include <string>
#include <vector>

#include "keywords/material.h"


namespace Keywords {

/* Manual reference : 4.13 */
class Density : public MaterialProp {
public:
	static const std::string keyName;

	Density(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

	virtual void appendToMaterial(Material *);

private:
	double value;
};

}

#endif //KEYWORDS_DENSITY_H