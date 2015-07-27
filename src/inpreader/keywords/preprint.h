#ifndef KEYWORDS_PREPRINT_H
#define KEYWORDS_PREPRINT_H

#include <string>

#include "keywords/keyword.h"


namespace Keywords {

/* Manual reference : 16.29 */
class Preprint : public Keyword {
public:
	static const std::string keyName;

	Preprint(Keyword * parent);
private:
};

}

#endif //KEYWORDS_PREPRINT_H