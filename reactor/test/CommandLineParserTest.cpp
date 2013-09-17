#include "CommandLineParser.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

class CommandLineParserTest: public ::testing::Test {
public:
	int argc;
	const char ** argv;
	std::vector<const char *> argument_buffer;
	std::vector<std::string> arguments;
	CommandLineParserTest(): argument_buffer(), arguments()
	{
		arguments.push_back("filename");
		arguments.push_back("100.0");
		arguments.push_back("0.0");
		argument_buffer.push_back(arguments[0].c_str());
		argument_buffer.push_back(arguments[1].c_str());
		argument_buffer.push_back(arguments[2].c_str());
		argv=&argument_buffer[0];
		argc=arguments.size();

	};
};

TEST_F(CommandLineParserTest, CommandLineParserCanParse) {
	CommandLineParser parser(argc,argv);
	EXPECT_EQ("filename",parser.GetReactionSystemFileName());
	std::vector<double> expected_initial_conditions;
	expected_initial_conditions.push_back(100.0);
	expected_initial_conditions.push_back(0.0);
	EXPECT_EQ(expected_initial_conditions,parser.GetInitialConditions());
}



int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}