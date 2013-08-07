#include "ReactionSystemParser.h"

ReactionSystem * ReactionSystemParser::FromStream(std::istream & source){
	ReactionSystem *result= new ReactionSystem();

	// The source stream is assumed to look like:
  	//
  	// A + B + C ->(rate) D
  	// D + E ->(rate2) A

  	// we need to, for each line,
 	{
 		std::vector<std::string> reactant_names;
 		std::vector<std::string> product_names;
 		double rate;
 		ParseLine(source, reactant_names, product_names, rate);
  	//	 create a new reaction with the rate
  	//   for each named species
  	//   	  determine if it is new
  	//  	  if it is new, create a species in the reaction system
  	//   	  if it is not new, obtain the species from the list of existing ones
  	//   for each reactant
  	//  	  add the species to the reactants
  	//   for each product
  	//  	  add the species to the products
  	//   determine the rate
 	}
  	return result;
}

void ReactionSystemParser::ParseLine(std::istream & source, std::vector<std::string>& reactant_names, std::vector<std::string> & product_names, double & rate){
	//   determine the reactant names
  	//   determine the rate
  	//   determine the product names
}