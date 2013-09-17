#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

reactor::ReactionSystem::ReactionSystem()
{
  // do nothing
}

reactor::Reaction & reactor::ReactionSystem::NewReaction(double rate) 
{ 
	reactions.push_back(new Reaction(rate));
	return *reactions.back();
}

reactor::Species & reactor::ReactionSystem::NewSpecies(const std::string &name){
	species.push_back(new Species(name));
	return *species.back();
}

reactor::ReactionSystem::~ReactionSystem(){
	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		delete *each_species;
	}
	for (std::vector< Reaction *>::iterator each_reaction=reactions.begin();each_reaction!=reactions.end();each_reaction++)
	{
		delete *each_reaction;
	}
}

const std::vector< double> reactor::ReactionSystem::GetConcentrations() const {
	std::vector<double> result;
	// we are not pre-allocating, this will be slow.
	// Idea is to try to make a maximally-readable solution without thinking about speed first.

	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		result.push_back((*each_species)->GetConcentration());
	}

	return result;
}

void reactor::ReactionSystem::SetConcentrations(const std::vector<double> & concentrations) {

	std::vector<double>::const_iterator each_concentration=concentrations.begin();

	for (std::vector<Species *>::iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		(*each_species)->SetConcentration(*each_concentration);
		each_concentration++;
	}
}

const std::vector<double> reactor::ReactionSystem::GetRatesOfChange() const {
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

 void reactor::ReactionSystem::GetRatesGivenConcentrations(const std::vector<double> & concentrations, std::vector<double> & rates){
 	SetConcentrations(concentrations);
 	rates=GetRatesOfChange();
 }

 std::ostream & operator<<(std::ostream &stream, const reactor::ReactionSystem& system){
 	for (std::vector<reactor::Reaction *>::const_iterator each_reaction=system.GetReactions().begin(); each_reaction!=system.GetReactions().end();each_reaction++)
	{
		stream << **each_reaction << std::endl;
	}
	return stream;
 }
