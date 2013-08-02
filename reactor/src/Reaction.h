#include <string> // use the string capabilities from the standard library
#include <vector>

#include "Species.h"

#ifndef ONCE_REACTION_H
#define ONCE_REACTION_H

typedef double RateConstant;

class Reaction // A "class" is a user defined type with built-in functions
{   
public:
  Reaction(const RateConstant & rate); // Declare constructor function.
  const RateConstant & GetRate();
private:
  RateConstant rate; // A member variable for the class to store the name of the system.
  std::vector<SpeciesReference> reactants;
  std::vector<SpeciesReference> products;
};

#endif //ONCE_REACTION_H
