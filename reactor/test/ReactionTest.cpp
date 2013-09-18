#include "Reaction.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class ReactionTest: public ::testing::Test {
protected:
	Reaction myReaction;
	ReactionTest():
		myReaction(5.0)
	{
	};
};

TEST_F(ReactionTest, ReactionHasRate) { // First argument is test group, second is test name
  EXPECT_EQ(5.0, myReaction.GetRate()); // Assert that the reaction rate should be as expected
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}