#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <memory>
#include <string>
#include <vector>

#include "tokens/token.h"


namespace Tokenizer {
	std::vector <std::shared_ptr <Tokens::Token> > fromFile(std::string filename);
};

#endif //TOKENIZER_H