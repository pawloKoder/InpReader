#ifndef KEYWORDS_CLOAD_H
#define KEYWORDS_CLOAD_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {
	
/* Manual reference : 3.21 */
class CLoad : public Keyword {
public:
	static const std::string keyName;

	CLoad(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

	struct ConcentratedLoadData {
		//Node number or node set label.
		std::string nodeSetLabel;
		// Degree of freedom.
		int deg;
		// Reference magnitude for load.
		double magnitude;
	};

private:
	std::vector<ConcentratedLoadData> load;
};

}

#endif //KEYWORDS_CLOAD_H