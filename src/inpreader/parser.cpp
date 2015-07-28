#include <parser.h>

#include <iostream>

#include "keywords/basekeyword.h"
#include "keywords/keyword.h"
#include "tokens/token.h"


std::shared_ptr <Model> Parser::parse(std::vector< std::shared_ptr< Tokens::Token > > tokens)
{
	Keywords::BaseKeyword root;
	Keywords::Keyword * current = &root;

	for (auto token : tokens) {
		try {
			current = token->appendToKeyword(current);
		} catch (std::exception e) {
			std::cerr << "Error with processing " << token->identifier() << " : " << e.what() << std::endl;
			break;
		}
	}
	
	return std::shared_ptr <Model> (new Model);
}