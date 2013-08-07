#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

ReactionSystem::ReactionSystem()
{
  // do nothing
}

Reaction & ReactionSystem::NewReaction(double rate) 
{ 
	reactions.push_back(new Reaction(rate));
	return *reactions.back();
}

Species & ReactionSystem::NewSpecies(const std::string &name){
	species.push_back(new Species(name));
	return *species.back();
}

ReactionSystem::~ReactionSystem(){
	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		delete *each_species;
	}
	for (std::vector< Reaction *>::iterator each_reaction=reactions.begin();each_reaction!=reactions.end();each_reaction++)
	{
		delete *each_reaction;
	}
}

const std::vector< double> ReactionSystem::GetConcentrations() const {
	std::vector<double> result;
	// we are not pre-allocating, this will be slow.
	// Idea is to try to make a maximally-readable solution without thinking about speed first.

	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		result.push_back((*each_species)->GetConcentration());
	}

	return result;
}

void ReactionSystem::SetConcentrations(const std::vector<double> & concentrations) {

	std::vector<double>::const_iterator each_concentration=concentrations.begin();

	for (std::vector<Species *>::iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		(*each_species)->SetConcentration(*each_concentration);
		each_concentration++;
	}
}

const std::vector<double> ReactionSystem::GetRatesOfChange() const {
	std::vector<double> rates_of_change;
	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		(*each_species)->ReSetRateOfChange();
	}

	for (std::vector<Reaction *>::const_iterator each_reaction=reactions.begin();each_reaction!=reactions.end();each_reaction++)
	{
		(*each_reaction)->ContributeToRatesOfChange();
	}

	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		rates_of_change.push_back((*each_species)->GetRateOfChange());
	}
	return rates_of_change;
}

 void ReactionSystem::GetRatesGivenConcentrations(const std::vector<double> & concentrations, std::vector<double> & rates){
 	SetConcentrations(concentrations);
 	rates=GetRatesOfChange();
 }

 std::ostream & operator<<(std::ostream &stream, const ReactionSystem& system){
 	for (std::vector<Reaction *>::const_iterator each_reaction=system.GetReactions().begin(); each_reaction!=system.GetReactions().end();each_reaction++)
	{
		stream << **each_reaction << std::endl;
	}
	return stream;
 }