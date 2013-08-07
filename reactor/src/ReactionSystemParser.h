#include <string> // use the string capabilities from the standard library
#include <vector>
#include <set>
#include <exception>
#include <iostream>

#include "ReactionSystem.h"


#ifndef ONCE_REACTIONSYSTEMPARSER_H
#define ONCE_REACTIONSYSTEMPARSER_H

class ReactionSystemParser
{   
public:
  ReactionSystemParser(){};
  ReactionSystem * FromStream(std::istream & source);
  void ParseLine(std::istream & source, std::vector<std::string>& reactant_names, std::vector<std::string> & product_names, double & rate);
private:

};


#endif //ONCE_REACTIONSYSTEMPARSER_H
