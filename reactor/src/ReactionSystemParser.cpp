#include "ReactionSystemParser.h"

ReactionSystem * ReactionSystemParser::FromStream(std::istream & source){
	return new ReactionSystem();
}