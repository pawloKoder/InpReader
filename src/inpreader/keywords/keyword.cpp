#include "keywords/keyword.h"

#include <iostream>

#include "settings.h"


Keywords::Keyword::Keyword(Keywords::Keyword * p):
	parent(p)
{}


Keywords::Keyword * Keywords::Keyword::appendComment(const Tokens::Comment * token)
{
	return this;
}


Keywords::Keyword * Keywords::Keyword::appendDataLine(const Tokens::DataLine * token)
{
	return parent->appendDataLine(token);
}


Keywords::Keyword * Keywords::Keyword::appendKeyword(const Tokens::Keyword * token)
{
	return parent->appendKeyword(token);
}


void Keywords::Keyword::appendToModel(InpReader::Model *)
{
	if (InpReader::verboseAppendToModel)
		std::cout << "Keyword: Append to model" << std::endl;
}


void Keywords::Keyword::appendToStep(InpReader::Step*, InpReader::Model*)
{
	if (InpReader::verboseAppendToStep)
		std::cout << "Keyword: Append to step" << std::endl;
}


void Keywords::Keyword::addParams(const std::map< std::string, std::string >&)
{

}