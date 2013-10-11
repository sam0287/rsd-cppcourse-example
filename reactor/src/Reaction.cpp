#include "Species.h" // Include the declaration of the Species..

reactor::Species::Species(const std::string &input_name, const float &input_concentration):
    name(input_name), // Initialise the name member variable from the input argument.
	concentration(input_concentration)
  {
    // do nothing
  }

const std::string & reactor::Species::GetName() const
{ 
	// a function whose return type is a standard string, with no input arguments
	// the ampersand and const will be explained later.
	return name; // give the name variable result back
}

const float & reactor::Species::GetConcentration() const
{ 
	// a function whose return type is a standard string, with no input arguments
	// the ampersand and const will be explained later.
	return concentration; // give the name variable result back
}