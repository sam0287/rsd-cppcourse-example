#include <string> // use the string capabilities from the standard library

class ReactionSystem // A "class" is a user defined type with built-in functions
{   
public:
  ReactionSystem(const std::string &input_name);
  const std::string & GetName();
private:
  std::string name; // A member variable for the class to store the name of the system.

};