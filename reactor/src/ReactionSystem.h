#include <string> // use the string capabilities from the standard library
#include <vector>
#include <set>
#include <exception>

#include "Species.h"
#include "Reaction.h"


#ifndef ONCE_REACTIONSYSTEM_H
#define ONCE_REACTIONSYSTEM_H

class ReactionSystem // A "class" is a user defined type with built-in functions
{   
public:
  ReactionSystem(); // Declare constructor function.
  void AddReaction(const Reaction& reaction);
  const std::vector<const Reaction *> & GetReactions() {return reactions;}
  
  const std::vector<double> GetRatesOfChange() const; // Given the current species concentrations, return the rates of change

  const std::vector<double> GetConcentrations() const ; // return array of species concentrations
  void SetConcentrations(const std::vector<double> & );



  void AddSpecies(Species * species);
  void AddSpecies(Species & species){AddSpecies(&species);}
  std::vector<Species *> & GetSpecies() { return species;}

  void operator()(const std::vector<double> & concentrations, std::vector<double> & rates, double time);

private:
 
  std::vector< const Reaction * > reactions;
  std::vector< Species * > species;
};
#endif //ONCE_REACTIONSYSTEM_H
