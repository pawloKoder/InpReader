#ifndef KEYWORDS_DYNAMIC_H
#define KEYWORDS_DYNAMIC_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 4.41 */
class Dynamic : public Keyword {
public:
	static const std::string keyName;

	Dynamic(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	//Initial time increment.
	double initialIncrement;
	
	//Time period of the step. 
	double timePeriod;
	
	//Minimum time increment allowed.
	double minIncrement;
	
	//Maximum time increment allowed. 
	double maxIncrement;
};

}

#endif //KEYWORDS_DYNAMIC_H