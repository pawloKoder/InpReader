#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>

#include "tokens/token.h"
#include "keywords/basekeyword.h"


namespace Parser {
	std::unique_ptr <Keywords::BaseKeyword> parse(std::vector <std::unique_ptr <Tokens::Token> >);
};

#endif //PARSER_H