#include "tokens/token.h"

#include <ostream>
#include <string>

#include "tokens/comment.h"
#include "tokens/dataline.h"
#include "tokens/keyword.h"


std::unique_ptr <Tokens::Token> Tokens::Token::fromString(std::string line)
{
	if (line.length() >= 2 && line[0] == '*' && line[1] == '*')
		return std::unique_ptr <Tokens::Comment> (new Tokens::Comment(line));
		
	if (line.length() >= 1 && line[0] == '*')
		return std::unique_ptr <Tokens::Keyword> (new Tokens::Keyword(line));
	
	return std::unique_ptr <Tokens::DataLine> (new Tokens::DataLine(line));
}


void Tokens::Token::print(std::ostream & stream) const
{
	stream << (*this);
}


std::ostream & Tokens::operator<< (std::ostream & stream, const Tokens::Token &) {
	stream << "Unknown token";
	return stream;
}



std::string Tokens::Token::identifier()
{
	return file + ":" + std::to_string(lineNum);
}