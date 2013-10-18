#include "Reaction.h" // Include the declaration of the Reaction..

reactor::Reaction::Reaction(RateConstant rate):
    rate(rate), reactants(), products()
{
    // do nothing
}

reactor::RateConstant reactor::Reaction::GetRate() const //const because it doesn't change rate
{
    return rate;//give the rate result back
}
  
double reactor::Reaction::GetFlux() const {
  // the product of the concentrations of the reactants, times the rate constant
  double flux=rate;
  for (std::vector<Species>::const_iterator each_reactant=GetReactants().begin(); each_reactant!=GetReactants().end();
  {
    flux*=each_reactant->GetConcentration();
  }
  return flux;
}