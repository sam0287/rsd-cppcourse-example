#include "ReactionSystemParser.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>

ReactionSystem * ReactionSystemParser::FromStream(std::istream & source){
	ReactionSystem *result= new ReactionSystem();

	// The source stream is assumed to look like:
  	//
  	// A + B + C -> rate D
  	// D + E -> rate2 A

  	// we need to, for each line,
  	while (source.good())
  	{
  		std::string line;
  		std::getline(source,line);
 		std::vector<std::string> reactant_names;
 		std::vector<std::string> product_names;
 		double rate(0.0);
 		ParseLine(line, reactant_names, product_names, rate);
 		if (rate!=0.0)
 		{
	 		result->NewReaction(rate);
 		}
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

void ReactionSystemParser::ParseLine(std::string & line, std::vector<std::string>& reactant_names, std::vector<std::string> & product_names, double & rate){
	std::string piece("");
	std::string separator("");
	bool found_reactants=false;
	// split the string by spaces
	std::vector<std::string> sections;
	boost::split(sections,line,boost::is_any_of(">"));
	if (sections.size()!=3)
	{
		return;
	}

	boost::split(reactant_names,sections[0],boost::is_any_of("+"));
	boost::split(product_names,sections[2],boost::is_any_of("+"));
	for (std::vector<std::string>::iterator reactant=reactant_names.begin(); reactant!=reactant_names.end(); reactant++)
	{
		boost::trim(*reactant);
	}
	for (std::vector<std::string>::iterator product=product_names.begin(); product!=product_names.end(); product++)
	{
		boost::trim(*product);
	}
	boost::trim(sections[1]);
	rate=boost::lexical_cast<double>(sections[1]);

}