#include <boost/lexical_cast.hpp>
#include "CommandLineParser.h"

CommandLineParser::CommandLineParser(int argument_count, const char **command_line_arguments):
	reaction_system_file_name(command_line_arguments[0])
{
	for (unsigned int i=1;i<argument_count;i++)
	{
		initial_conditions.push_back(boost::lexical_cast<double>(command_line_arguments[i]));
	}
}
