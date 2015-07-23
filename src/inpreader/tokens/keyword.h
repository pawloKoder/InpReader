#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>
#include <map>


namespace Token {

struct Keyword {
	std::string name;
	
	std::map <std::string, std::string> parameters;
};

}

#endif //KEYWORD_H