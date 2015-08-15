#ifndef KEYWORD_H
#define KEYWORD_H

#include <map>
#include <string>


namespace InpReader {

class Model;
class Step;

}

namespace Tokens {

class Comment;
class DataLine;
class Keyword;

}


namespace Keywords {

class Keyword {
public:
	Keyword(Keyword * parent);

	virtual Keywords::Keyword * appendComment(const Tokens::Comment *);
	virtual Keywords::Keyword * appendDataLine(const Tokens::DataLine *);
	virtual Keywords::Keyword * appendKeyword(const Tokens::Keyword *);

	virtual void appendToModel(InpReader::Model *);
	virtual void appendToStep(InpReader::Step *, InpReader::Model *);

	virtual void addParams(const std::map <std::string, std::string> &);
protected:
	Keyword * parent;
};

}

#endif //KEYWORD_H