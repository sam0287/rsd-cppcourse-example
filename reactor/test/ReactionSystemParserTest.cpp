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

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}