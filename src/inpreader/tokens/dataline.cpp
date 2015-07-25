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