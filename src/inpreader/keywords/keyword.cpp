#include "keywords/keyword.h"

#include <iostream>


Keywords::Keyword::Keyword(Keywords::Keyword * p):
	parent(p)
{}


Keywords::Keyword * Keywords::Keyword::appendComment(const Tokens::Comment * token)
{
	return parent->appendComment(token);
}


Keywords::Keyword * Keywords::Keyword::appendDataLine(const Tokens::DataLine * token)
{
	return parent->appendDataLine(token);
}


Keywords::Keyword * Keywords::Keyword::appendKeyword(const Tokens::Keyword * token)
{
	return parent->appendKeyword(token);
}


