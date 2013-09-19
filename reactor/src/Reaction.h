#include <string> // use the string capabilities from the standard library
#include <vector>
#include <iostream>

#include "Species.h"

#ifndef ONCE_REACTION_H
#define ONCE_REACTION_H


namespace reactor{

  typedef double RateConstant;

  class Reaction // A "class" is a user defined type with built-in functions
  {   
  public:
    Reaction(RateConstant rate); // Declare constructor function.
    RateConstant GetRate() const; // Const because it doesn't change the rate

  private:

    RateConstant rate; // A member variable for the class to store the reaction rate
  };
}

#endif //ONCE_REACTION_H
