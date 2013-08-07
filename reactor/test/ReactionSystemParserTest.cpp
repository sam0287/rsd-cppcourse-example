#include "ReactionSystemParser.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

class ReactionSystemParserTest: public ::testing::Test {
protected:
	ReactionSystemParser parser;
	ReactionSystemParserTest():
		parser()
	{
	};
};

TEST_F(ReactionSystemParserTest, ParserCanStart) {
	std::istringstream buffer("");
	ReactionSystem * system = parser.FromStream(buffer);
	ASSERT_EQ(0,system->GetSpecies().size());
	delete system;
}


TEST_F(ReactionSystemParserTest, ParseLine) {
	std::string source("A + B > 2.0 > C + D");
	std::vector<std::string> reactant_names;
 	std::vector<std::string> product_names;
 	double rate(0.0);
 	parser.ParseLine(source, reactant_names, product_names, rate);
 	std::vector<std::string> expected_reactant_names;
 	std::vector<std::string> expected_product_names;
 	expected_reactant_names.push_back("A");
 	expected_reactant_names.push_back("B");
 	expected_product_names.push_back("C");
 	expected_product_names.push_back("D");
 	EXPECT_EQ(expected_product_names,product_names);
 	EXPECT_EQ(expected_reactant_names,reactant_names);
 	EXPECT_EQ(2.0,rate);
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}