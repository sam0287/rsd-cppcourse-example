#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

ReactionSystem::ReactionSystem()
{
  // do nothing
}

Species* ReactionSystem::NewSpecies(const std::string &name){
	species.push_back(name);
	return &species.back();
}

std::vector< Species > & ReactionSystem::GetSpecies(){
	return species;
}