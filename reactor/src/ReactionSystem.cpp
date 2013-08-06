#include "ReactionSystem.h" // Include the declaration of the ReactionSystem..

ReactionSystem::ReactionSystem()
{
  // do nothing
}

void ReactionSystem::AddReaction(const Reaction& reaction) 
{ 
	reactions.push_back(&reaction); 
}