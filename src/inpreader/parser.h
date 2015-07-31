#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>

#include "tokens/token.h"


namespace Keywords {
	class BaseKeyword;
}


namespace Parser {
	std::shared_ptr <Keywords::BaseKeyword> parse(std::vector <std::shared_ptr <Tokens::Token> >);
};

#endif //PARSER_H