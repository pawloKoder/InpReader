#include "tokens/keyword.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <functional>
#include <string>


Tokens::Keyword::Keyword(std::string line)
{
	std::vector <std::string> tokens;
	boost::split(tokens, line, boost::is_any_of(","));
	std::for_each(tokens.begin(), tokens.end(), 
		std::bind(boost::trim <std::string>, std::placeholders::_1, std::locale()));
	
	name = tokens[0].substr(1);
	
	tokens.erase(tokens.begin());
	
	for (auto token : tokens) {
		std::size_t equPosition = token.find("=");
		parameters[token.substr(0, equPosition)] = token.substr(equPosition+1);
	}
}
