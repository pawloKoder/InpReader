#include "tokens/comment.h"

#include "keywords/keyword.h"


Tokens::Comment::Comment(std::string line) :
	content(line.substr(2))
{}


void Tokens::Comment::print(std::ostream & stream) const
{
	stream << (*this);
}


Keywords::Keyword *  Tokens::Comment::appendToKeyword(Keywords::Keyword * keyword)
{
	return keyword->appendComment(this);
}


std::ostream & Tokens::operator<< (std::ostream & stream, const Tokens::Comment & comment) {
	stream << "Comment : " << comment.content;
	return stream;
}
