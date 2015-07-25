#include "tokens/comment.h"


Tokens::Comment::Comment(std::string line) :
	content(line.substr(2))
{}


void Tokens::Comment::print(std::ostream & stream) const
{
	stream << (*this);
}


std::ostream & Tokens::operator<< (std::ostream & stream, const Tokens::Comment & comment) {
	stream << "Comment : " << comment.content;
	return stream;
}
