#include "Reaction.h" // Include the declaration of the Reaction..

reactor::Reaction::Reaction(RateConstant rate):
    rate(rate)
  {
    // do nothing
  }

reactor::RateConstant reactor::Reaction::GetRate() const
{ 
	// a function whose return type is a standard string, with no input arguments
	// the ampersand and const will be explained later.
	return rate; // give the name variable result back
}