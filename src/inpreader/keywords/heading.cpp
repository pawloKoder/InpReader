#include "keywords/heading.h"

#include "tokens/comment.h"


const std::string Keywords::Heading::keyName = "Heading";


Keywords::Heading::Heading(Keywords::Keyword* parent): Keyword(parent)
{}


Keywords::Keyword* Keywords::Heading::appendComment(const Tokens::Comment * token)
{
	content += token->content + "\n";
	return this;
}
