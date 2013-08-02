#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

ReactionSystem::ReactionSystem(const std::string &input_name):
    name(input_name) // Initialise the name member variable from the input argument.
  {
    // do nothing
  }

const std::string & ReactionSystem::GetName() 
{ 
	// a function whose return type is a standard string, with no input arguments
	// the ampersand and const will be explained later.
	return name; // give the name variable result back
}

