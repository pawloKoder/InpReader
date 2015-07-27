#include <parser.h>

#include "keywords/basekeyword.h"
#include "keywords/keyword.h"
#include "tokens/token.h"


std::shared_ptr <Model> Parser::parse(std::vector< std::shared_ptr< Tokens::Token > > tokens)
{
	Keywords::BaseKeyword root;
	Keywords::Keyword * current = &root;
	
	for (auto token : tokens) {
		current = token->appendToKeyword(current);
	}
	
	return std::shared_ptr <Model> (new Model);
}