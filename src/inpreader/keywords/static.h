#ifndef KEYWORDS_STATIC_H
#define KEYWORDS_STATIC_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 18.31 */
class Static : public Keyword {
public:
	static const std::string keyName;

	Static(Keyword * parent);

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

#endif //KEYWORDS_STATIC_H