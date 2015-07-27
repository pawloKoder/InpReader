#include "keywords/heading.h"

#include <iostream>

#include "tokens/comment.h"


const std::string Keywords::Heading::keyName = "Heading";


Keywords::Heading::Heading(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Heading::appendComment(const Tokens::Comment * token)
{
	std::cout << "Heading Append Comment\n";
	content += token->content + "\n";
	return this;
}
