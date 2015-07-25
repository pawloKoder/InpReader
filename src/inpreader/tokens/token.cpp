#include "tokens/token.h"

#include <ostream>

#include "tokens/comment.h"
#include "tokens/dataline.h"
#include "tokens/keyword.h"


std::shared_ptr <Tokens::Token> Tokens::Token::fromString(std::string line)
{
	if (line.length() >= 2 && line[0] == '*' && line[1] == '*')
		return std::shared_ptr <Tokens::Comment> (new Comment(line));
		
	if (line.length() >= 1 && line[0] == '*')
		return std::shared_ptr <Tokens::Keyword> (new Keyword(line));
	
	return std::shared_ptr <Tokens::DataLine> (new DataLine(line));
}


void Tokens::Token::print(std::ostream & stream) const
{
	stream << (*this);
}


std::ostream & Tokens::operator<< (std::ostream & stream, const Tokens::Token &) {
	stream << "Unknown token";
	return stream;
}