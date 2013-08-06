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
  void AddReaction(const Reaction& reaction);
  const std::vector<const Reaction *> & GetReactions() {return reactions;}

private:
  std::vector< const Reaction * > reactions;
  std::vector< Species * > species;
};

#endif //ONCE_REACTIONSYSTEM_H
