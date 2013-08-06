#include "ReactionSystem.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

class ReactionSystemTest: public ::testing::Test {
protected:
	ReactionSystem myReactionSystem;
	Reaction forward;
	Reaction reverse;
	Species calcium;
	Species carbon;
	Species oxygen;
	Species calcium_carbonate;

	ReactionSystemTest():
		forward(5.0),
		reverse(5.0), 
		calcium("Ca"), 
		carbon("C"), 
		oxygen("O"), 
		calcium_carbonate("CaCO3")
	{
		forward.AddReactant(calcium);
		forward.AddReactant(carbon);
		forward.AddReactant(oxygen);
		forward.AddProduct(calcium_carbonate);

		reverse.AddProduct(calcium);
		reverse.AddProduct(carbon);
		reverse.AddProduct(oxygen);
		reverse.AddReactant(calcium_carbonate);
	};
};

// Test that the system has a name as expected.
TEST_F(ReactionSystemTest, ReactionSystemCanHaveReaction) { // First argument is test group, second is test name
  myReactionSystem.AddReaction(forward);
  ASSERT_EQ(1,myReactionSystem.GetReactions().size());
  ASSERT_EQ(&forward,myReactionSystem.GetReactions()[0]);
}

// Test that the system has a name as expected.
TEST_F(ReactionSystemTest, ReactionSystemCanHaveMultipleReactions) { // First argument is test group, second is test name
  myReactionSystem.AddReaction(forward);
  myReactionSystem.AddReaction(reverse);
  ASSERT_EQ(2,myReactionSystem.GetReactions().size());
  ASSERT_EQ(&forward,myReactionSystem.GetReactions()[0]);
  ASSERT_EQ(&reverse,myReactionSystem.GetReactions()[1]);
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}