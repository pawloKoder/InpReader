#ifndef KEYWORDS_DSLOAD_H
#define KEYWORDS_DSLOAD_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 4.40 */
class DSLoad : public Keyword {
public:
	static const std::string keyName;

	DSLoad(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual void appendToStep(InpReader::Step*, InpReader::Model*);

	struct DistributedSurfaceData {
		//Surface name.
		std::string name;
		//Distributed load type.
		std::string type;
		//Magnitude
		double magnitude;
	};

private:
	std::vector<DistributedSurfaceData> loads;
};

}

#endif //KEYWORDS_DSLOAD_H