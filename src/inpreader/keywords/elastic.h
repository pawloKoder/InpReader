#ifndef KEYWORDS_ELASTIC_H
#define KEYWORDS_ELASTIC_H

#include <string>
#include <vector>

#include "keywords/material.h"


namespace Keywords {

/* Manual reference : 5.3 */
class Elastic : public MaterialProp {
public:
	static const std::string keyName;

	Elastic(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	
	virtual void appendToMaterial(Material *);

private:
	std::vector<double> modules;
};

}

#endif //KEYWORDS_ELASTIC_H