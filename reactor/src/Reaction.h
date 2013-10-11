#include <string> // use the string capabilities from the standard library

#ifndef ONCE_SPECIES_H
#define ONCE_SPECIES_H

namespace reactor
{

  class Species // A "class" is a user defined type with built-in functions
  {   
  public:
    Species(const std::string &input_name, const float &input_concentration); // Declare constructor function.
    const std::string & GetName() const; // Declare a get name function.
	const float & GetConcentration() const; // Declare a get concentration function.
	
	
  private:
    std::string name; // A member variable for the class to store the name of the system.
	float concentration;
  };
}

#endif //ONCE_SPECIES_H
