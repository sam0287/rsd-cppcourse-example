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

		calcium.SetConcentration(2.0);
		carbon.SetConcentration(3.0);
		oxygen.SetConcentration(5.0);
		calcium_carbonate.SetConcentration(7.0);
	};
};

// Test that the system has a name as expected.
TEST_F(ReactionSystemTest, ReactionSystemCanHaveReaction) { // First argument is test group, second is test name
  myReactionSystem.AddReaction(forward);
  ASSERT_EQ(1, myReactionSystem.GetReactions().size());
  ASSERT_EQ(&forward, myReactionSystem.GetReactions()[0]);
}

// Test that the system has a name as expected.
TEST_F(ReactionSystemTest, ReactionSystemCanHaveMultipleReactions) { // First argument is test group, second is test name
  myReactionSystem.AddReaction(forward);
  myReactionSystem.AddReaction(reverse);
  ASSERT_EQ(2, myReactionSystem.GetReactions().size());
  ASSERT_EQ(&forward, myReactionSystem.GetReactions()[0]);
  ASSERT_EQ(&reverse, myReactionSystem.GetReactions()[1]);
}

TEST_F(ReactionSystemTest, ReactionSystemCanGiveConcentrations) {
	myReactionSystem.AddReaction(forward);
	std::vector<double> expectation;
	expectation.push_back(2.0);
	expectation.push_back(3.0);
	expectation.push_back(5.0);
	expectation.push_back(7.0);
	ASSERT_EQ(expectation,myReactionSystem.GetConcentrations());
}

TEST_F(ReactionSystemTest, ReactionSystemCanSetConcentrations) {
	myReactionSystem.AddReaction(forward);
	std::vector<double> initial_state;
	initial_state.push_back(2.0);
	initial_state.push_back(3.0);
	initial_state.push_back(5.0);
	initial_state.push_back(7.0);
	ASSERT_EQ(initial_state, myReactionSystem.GetConcentrations());

	std::vector<double> expectation;
	expectation.push_back(9.0);
	expectation.push_back(11.0);
	expectation.push_back(13.0);
	expectation.push_back(17.0);
	myReactionSystem.SetConcentrations(expectation);
	ASSERT_EQ(expectation,myReactionSystem.GetConcentrations());
}

TEST_F(ReactionSystemTest, ReactionSystemGivesSpecies){
	myReactionSystem.AddReaction(forward);
	std::vector<Species *> expectation;
	expectation.push_back(&calcium);
	expectation.push_back(&carbon);
	expectation.push_back(&oxygen);
	expectation.push_back(&calcium_carbonate);
	ASSERT_EQ(expectation,myReactionSystem.GetSpecies());
}

TEST_F(ReactionSystemTest, ReactionSystemCanAddSpecies){
	myReactionSystem.AddSpecies(&calcium);
	myReactionSystem.AddSpecies(&carbon);
	std::vector<Species *> expectation;
	expectation.push_back(&calcium);
	expectation.push_back(&carbon);
	ASSERT_EQ(expectation,myReactionSystem.GetSpecies());
}

TEST_F(ReactionSystemTest, ReactionSystemIgnoresDuplicateSpecies){
	myReactionSystem.AddSpecies(&calcium);
	myReactionSystem.AddSpecies(&carbon);
	myReactionSystem.AddSpecies(&carbon);
	std::vector<Species *> expectation;
	expectation.push_back(&calcium);
	expectation.push_back(&carbon);
	ASSERT_EQ(expectation,myReactionSystem.GetSpecies());
}

TEST_F(ReactionSystemTest, ReactionSystemIgnoresManyDuplicateSpecies){
	myReactionSystem.AddReaction(forward);
    myReactionSystem.AddReaction(reverse);
	std::vector<Species *> expectation;
	expectation.push_back(&calcium);
	expectation.push_back(&carbon);
	expectation.push_back(&oxygen);
	expectation.push_back(&calcium_carbonate);
	ASSERT_EQ(expectation,myReactionSystem.GetSpecies());
}



int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}