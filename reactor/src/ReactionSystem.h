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
  const std::vector<const Reaction *> & GetReactions() const {return reactions;}
  
  const std::vector<double> GetRatesOfChange() const; // Given the current species concentrations, return the rates of change

  const std::vector<double> GetConcentrations() const ; // return array of species concentrations
  void SetConcentrations(const std::vector<double> & );

  const std::vector<Species *> & GetSpecies() const { return species;}

  void operator()(const std::vector<double> & concentrations, std::vector<double> & rates, double time);
  Species & NewSpecies(const std::string &name);

private:
 
  std::vector< const Reaction * > reactions;
  std::vector< Species * > species;
};

std::ostream & operator<<(std::ostream &s, const ReactionSystem& system);

#endif //ONCE_REACTIONSYSTEM_H
