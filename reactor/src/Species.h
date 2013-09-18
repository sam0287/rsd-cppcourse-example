#include <string> // use the string capabilities from the standard library

#ifndef ONCE_SPECIES_H
#define ONCE_SPECIES_H

namespace reactor
{

  class Species // A "class" is a user defined type with built-in functions
  {   
  public:
    Species(const std::string &input_name); // Declare constructor function.
    const std::string & GetName() const;// Declare a get name function.
    void   SetConcentration(double new_concentration) {concentration=new_concentration;} // Set concentration
    double GetConcentration() const {return concentration;}

  private:
    std::string name; // A member variable for the class to store the name of the system.
    double concentration;
    double rate_of_change;
  };
}

#endif //ONCE_SPECIES_H
