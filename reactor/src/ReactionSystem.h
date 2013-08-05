#include <string> // use the string capabilities from the standard library
#include <vector>

#include "Species.h"
#include "Reaction.h"

#ifndef ONCE_REACTIONSYSTEM_H
#define ONCE_REACTIONSYSTEM_H

class ReactionSystem // A "class" is a user defined type with built-in functions
{   
public:
  ReactionSystem(); // Declare constructor function.
  Species* NewSpecies(const std::string & name);
  std::vector< Species > & GetSpecies();
  
private:
  std::vector< Reaction > reactions;
  std::vector< Species > species;
};

#endif //ONCE_REACTIONSYSTEM_H
