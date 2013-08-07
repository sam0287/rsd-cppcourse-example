#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

ReactionSystem::ReactionSystem()
{
  // do nothing
}

void ReactionSystem::AddReaction(const Reaction& reaction) 
{ 
	reactions.push_back(&reaction);
}

void ReactionSystem::AddSpecies(Species * new_species)
{
	species.push_back(new_species);
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

	for (std::vector<const Reaction *>::const_iterator each_reaction=reactions.begin();each_reaction!=reactions.end();each_reaction++)
	{
		(*each_reaction)->ContributeToRatesOfChange();
	}

	for (std::vector<Species *>::const_iterator each_species=species.begin();each_species!=species.end();each_species++)
	{
		rates_of_change.push_back((*each_species)->GetRateOfChange());
	}
	return rates_of_change;
}

 void ReactionSystem::operator()(const std::vector<double> & concentrations, std::vector<double> & rates, double time){
 	SetConcentrations(concentrations);
 	rates=GetRatesOfChange();
 }

 std::ostream & operator<<(std::ostream &stream, const ReactionSystem& system){
 	for (std::vector<const Reaction *>::const_iterator each_reaction=system.GetReactions().begin(); each_reaction!=system.GetReactions().end();each_reaction++)
	{
		stream << **each_reaction << std::endl;
	}
	return stream;
 }
