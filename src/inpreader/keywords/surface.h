#ifndef KEYWORDS_SURFACE_H
#define KEYWORDS_SURFACE_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 18.47 */
class Surface : public Keyword {
public:
	static const std::string keyName;

	Surface(Keyword * parent);
    
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	std::string name;
	
	// The current only suported surface is TYPE=ELEMENT
	std::vector<std::string> elementSet;
	
	/* Face or edge identifier label (see “Element-based surface definition,” Section 2.3.2 of the
		Abaqus Analysis User’s Manual, for the face and edge identifiers for various elements) or
		the “word” EDGE (optional).
	*/
	std::vector<std::string> face;
};

}

#endif //KEYWORDS_SURFACE_H