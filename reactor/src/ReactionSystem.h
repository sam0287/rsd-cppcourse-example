#include <string> // use the string capabilities from the standard library

class ReactionSystem // A "class" is a user defined type with built-in functions
{   
public:
  ReactionSystem(std::string input_name):
    name(input_name) // Initialise the name member variable from the input argument.
  {
    // do nothing
  }
  const std::string & GetName(){ // a function whose return type is a standard string, with no input arguments
    // the ampersand and const will be explained later.
    return name; // give the name variable result back
  }
private:
  std::string name; // A member variable for the class to store the name of the system.

};