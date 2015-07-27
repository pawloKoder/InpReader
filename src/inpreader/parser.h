#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>

#include "model.h"
#include "tokens/token.h"


namespace Parser {
	std::shared_ptr <Model> parse(std::vector <std::shared_ptr <Tokens::Token> >);
};

#endif //PARSER_H