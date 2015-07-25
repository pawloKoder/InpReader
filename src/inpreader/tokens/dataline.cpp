#include "tokens/dataline.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <functional>
#include <string>


Tokens::DataLine::DataLine(std::string line)
{
	boost::split(data, line, boost::is_any_of(","));
	std::for_each(data.begin(), data.end(), 
		std::bind(boost::trim <std::string>, std::placeholders::_1, std::locale()));
}


void Tokens::DataLine::print(std::ostream & stream) const
{
	stream << (*this);
}


std::ostream & Tokens::operator<< (std::ostream & stream, const Tokens::DataLine & data) {
	stream << "Dataline : ";
	for (auto item : data.data)
		stream << item << "; ";
	return stream;
}