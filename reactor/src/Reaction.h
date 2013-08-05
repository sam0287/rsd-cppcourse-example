#include <string> // use the string capabilities from the standard library
#include <vector>

#include "Species.h"

#ifndef ONCE_REACTION_H
#define ONCE_REACTION_H

typedef double RateConstant;

class Reaction // A "class" is a user defined type with built-in functions
{   
public:
  Reaction(RateConstant rate); // Declare constructor function.
  RateConstant GetRate(); const

  void AddReactant(const Species * const species){reactants.push_back(species);}
  void AddProduct(const Species  * const species){products.push_back(species);}

  void AddReactant(const Species &  species){reactants.push_back(&species);}
  void AddProduct(const Species  &  species){products.push_back(&species);}

  const std::vector< const Species * > GetReactants() const { return reactants;}
  const std::vector< const Species * > GetProducts() const { return products;}
private:
  RateConstant rate; // A member variable for the class to store the name of the system.
  std::vector< const Species * > reactants;
  std::vector< const Species * > products;
};

#endif //ONCE_REACTION_H
