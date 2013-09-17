#include "ReactionSystem.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class ReactionSystemTest: public ::testing::Test {
protected:
	ReactionSystem myReactionSystem;
	ReactionSystem emptyReactionSystem;
	Reaction &forward;
	Reaction &reverse;
	Species &calcium;
	Species &carbon;
	Species &oxygen;
	Species &calcium_carbonate;

	ReactionSystemTest():
		myReactionSystem(),
		forward(myReactionSystem.NewReaction(9.0)),
		reverse(myReactionSystem.NewReaction(11.0)), 
		calcium(myReactionSystem.NewSpecies("Ca")),
		oxygen(myReactionSystem.NewSpecies("O")),
		carbon(myReactionSystem.NewSpecies("C")),
		calcium_carbonate(myReactionSystem.NewSpecies("CaCO3"))
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

TEST_F(ReactionSystemTest, ReactionSystemCanHaveReaction) { // First argument is test group, second is test name
  Reaction & new_forward= emptyReactionSystem.NewReaction(9.0);
  EXPECT_EQ(1, emptyReactionSystem.GetReactions().size());
  EXPECT_EQ(&new_forward, emptyReactionSystem.GetReactions()[0]);
}

TEST_F(ReactionSystemTest, ReactionSystemCanHaveMultipleReactions) { 
  Reaction & new_forward = emptyReactionSystem.NewReaction(9.0);
  Reaction & new_back = emptyReactionSystem.NewReaction(11.0);
  EXPECT_EQ(2, emptyReactionSystem.GetReactions().size());
  EXPECT_EQ(&new_forward, emptyReactionSystem.GetReactions()[0]);
  EXPECT_EQ(&new_back, emptyReactionSystem.GetReactions()[1]);
}

TEST_F(ReactionSystemTest, ReactionSystemReactionCanBeModifiedByReference){
  Reaction & new_forward = emptyReactionSystem.NewReaction(9.0);
  Species & new_calcium = emptyReactionSystem.NewSpecies("Ca");
  EXPECT_EQ(0, emptyReactionSystem.GetReactions()[0]->GetReactants().size());
  new_forward.AddReactant(new_calcium);
  EXPECT_EQ(&new_calcium, emptyReactionSystem.GetReactions()[0]->GetReactants()[0]);
}

TEST_F(ReactionSystemTest, ReactionSystemCanGiveConcentrations) {
	std::vector<double> expectation;
	expectation.push_back(2.0);
	expectation.push_back(3.0);
	expectation.push_back(5.0);
	expectation.push_back(7.0);
	EXPECT_EQ(expectation,myReactionSystem.GetConcentrations());
}

TEST_F(ReactionSystemTest, ReactionSystemCanSetConcentrations) {
	std::vector<double> initial_state;
	initial_state.push_back(2.0);
	initial_state.push_back(3.0);
	initial_state.push_back(5.0);
	initial_state.push_back(7.0);
	EXPECT_EQ(initial_state, myReactionSystem.GetConcentrations());

	std::vector<double> expectation;
	expectation.push_back(9.0);
	expectation.push_back(11.0);
	expectation.push_back(13.0);
	expectation.push_back(17.0);
	myReactionSystem.SetConcentrations(expectation);
	EXPECT_EQ(expectation,myReactionSystem.GetConcentrations());
}

TEST_F(ReactionSystemTest, ReactionSystemCanAddSpecies){
	Species & newCalcium = emptyReactionSystem.NewSpecies("Ca");
	Species & newCarbon = emptyReactionSystem.NewSpecies("C");
	ASSERT_EQ(2,emptyReactionSystem.GetSpecies().size());
	EXPECT_EQ(&newCalcium,emptyReactionSystem.GetSpecies()[0]);
	EXPECT_EQ(&newCarbon,emptyReactionSystem.GetSpecies()[1]);

}

TEST_F(ReactionSystemTest, ReactionSystemSpeciesCanBeModifiedByReference){
	Species & newCalcium = emptyReactionSystem.NewSpecies("Ca");
	EXPECT_EQ(0,emptyReactionSystem.GetSpecies()[0]->GetConcentration());
	newCalcium.SetConcentration(2.0);
	EXPECT_EQ(2.0,emptyReactionSystem.GetSpecies()[0]->GetConcentration());
}

TEST_F(ReactionSystemTest, ReactionSystemCanDetermineRatesOfChange){
	std::vector<double> rates_of_change;
	rates_of_change.push_back(-9.0*2.0*3.0*5.0+11.0*7.0); //calcium
	rates_of_change.push_back(-9.0*2.0*3.0*5.0+11.0*7.0); //carbon
	rates_of_change.push_back(-9.0*2.0*3.0*5.0+11.0*7.0); //oxygen
	rates_of_change.push_back(9.0*2.0*3.0*5.0-11.0*7.0); //calcium carbonate
	EXPECT_EQ(rates_of_change,myReactionSystem.GetRatesOfChange());
}

TEST_F(ReactionSystemTest, ReactionSystemCanDetermineRatesOfChangeInFormatExpectedByODEINT){
	std::vector<double> expected_rates_of_change;
	expected_rates_of_change.push_back(-9.0*9.0*11.0*13.0+11.0*17.0); //calcium
	expected_rates_of_change.push_back(-9.0*9.0*11.0*13.0+11.0*17.0); //carbon
	expected_rates_of_change.push_back(-9.0*9.0*11.0*13.0+11.0*17.0); //oxygen
	expected_rates_of_change.push_back(9.0*9.0*11.0*13.0-11.0*17.0); //calcium carbonate

	std::vector<double> concentrations;
	concentrations.push_back(9.0);
	concentrations.push_back(11.0);
	concentrations.push_back(13.0);
	concentrations.push_back(17.0);

	std::vector<double> actual_rates_of_change;
	myReactionSystem.GetRatesGivenConcentrations(concentrations,actual_rates_of_change);

	EXPECT_EQ(expected_rates_of_change,actual_rates_of_change);
}

TEST_F(ReactionSystemTest, ReactionSystemCanOutputToAStream) {
	std::ostringstream output_buffer;
	output_buffer << myReactionSystem;

	EXPECT_EQ("Ca + C + O > 9 > CaCO3\nCaCO3 > 11 > Ca + C + O\n", output_buffer.str());
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}