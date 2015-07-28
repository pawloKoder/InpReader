#ifndef KEYWORDS_BOUNDARY_H
#define KEYWORDS_BOUNDARY_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 2.11 */
class Boundary : public Keyword {
public:
	static const std::string keyName;

	Boundary(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	// Node number or node set label.
	std::vector <std::string> nodeSetLabel;
	
	// Label specifying the type of boundary condition to be applied 
	std::vector <std::string> boundaryType;
};

}

#endif //KEYWORDS_BOUNDARY_H