#include <parser.h>

#include <iostream>

#include "keywords/basekeyword.h"
#include "keywords/keyword.h"
#include "tokens/token.h"


std::shared_ptr <Keywords::BaseKeyword> Parser::parse(std::vector < std::shared_ptr< Tokens::Token > > tokens)
{
	std::shared_ptr <Keywords::BaseKeyword> root(new Keywords::BaseKeyword);
	Keywords::Keyword * current = root.get();

	for (auto token : tokens) {
		try {
			current = token->appendToKeyword(current);
		} catch (std::exception e) {
			std::cerr << "Error with processing " << token->identifier() << " : " << e.what() << std::endl;
			break;
		}
	}
	
	return root;
}