#include "Reaction.h" // Include the declaration of the Reaction..

Reaction::Reaction(RateConstant rate):
    rate(rate), reactants(), products() // Initialise the name member variable from the input argument.
  {
    // do nothing
  }

RateConstant Reaction::GetRate() 
{ 
	// a function whose return type is a standard string, with no input arguments
	// the ampersand and const will be explained later.
	return rate; // give the name variable result back
}