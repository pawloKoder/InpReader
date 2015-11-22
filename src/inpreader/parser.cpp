#include <parser.h>

#include <iostream>

#include "keywords/basekeyword.h"
#include "keywords/keyword.h"
#include "tokens/token.h"


std::unique_ptr <Keywords::BaseKeyword> Parser::parse(std::vector < std::unique_ptr< Tokens::Token > > tokens)
{
	std::unique_ptr <Keywords::BaseKeyword> root(new Keywords::BaseKeyword);
	Keywords::Keyword * current = root.get();

	for (const auto & token : tokens) {
		try {
			current = token->appendToKeyword(current);
		} catch (std::exception& e) {
			std::cerr << "Error with processing " << token->identifier() << " : " << e.what() << std::endl;
			break;
		}
	}
	
	return root;
}