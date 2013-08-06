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

void Reaction::ContributeToRatesOfChange() const 
{

}

double  Reaction::GetFlux() const {
	// the product of the concentrations of the reactants, times the rate constant
	double flux=rate;
	for (std::vector<Species *>::const_iterator each_reactant=GetReactants().begin(); each_reactant!=GetReactants().end(); each_reactant++)
	{
		flux*=(*each_reactant)->GetConcentration();
	}
	return flux;
}