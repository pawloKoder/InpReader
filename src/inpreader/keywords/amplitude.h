#ifndef KEYWORDS_AMPLITUDE_H
#define KEYWORDS_AMPLITUDE_H

#include <string>
#include <vector>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 4.41 */
class Amplitude : public Keyword {
public:
	static const std::string keyName;

	Amplitude(Keyword * parent);

	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);

private:
	std::vector<double> parameters;
};

}

#endif //KEYWORDS_AMPLITUDE_H