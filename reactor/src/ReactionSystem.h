#include <string> // use the string capabilities from the standard library

#ifndef ONCE_REACTION_SYSTEM_H
#define ONCE_REACTION_SYSTEM_H

class ReactionSystem // A "class" is a user defined type with built-in functions
{   
public:
  ReactionSystem(const std::string &input_name); // Declare constructor function.
  const std::string & GetName(); // Declare a get name function.
private:
  std::string name; // A member variable for the class to store the name of the system.

};

#endif //ONCE_REACTION_SYSTEM_H