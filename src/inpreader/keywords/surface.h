#ifndef SURFACE_H
#define SURFACE_H


#include <string>


class ElementSet;


/* Manual reference : 18.47 */
class Surface {
	std::string name;
	
	// The current only suported surface is TYPE=ELEMENT
	ElementSet *elements;
	
	/* Face or edge identifier label (see “Element-based surface definition,” Section 2.3.2 of the
		Abaqus Analysis User’s Manual, for the face and edge identifiers for various elements) or
		the “word” EDGE (optional).
	*/
	std::string face;
};

#endif //SURFACE_H