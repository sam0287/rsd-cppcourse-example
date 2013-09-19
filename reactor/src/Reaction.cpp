#include "Reaction.h" // Include the declaration of the Reaction..

reactor::Reaction::Reaction(RateConstant rate):
    rate(rate), reactants(), products()
  {
    // do nothing
  }

reactor::RateConstant reactor::Reaction::GetRate() const // const because it doesn't change the rate
{ 
	return rate; // give the rate result back
}