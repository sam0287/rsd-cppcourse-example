#include "Reaction.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

class ReactionTest: public ::testing::Test {
protected:
  Reaction myReaction;
  ReactionTest():
    myReaction()
  {
  };
};

// Not sure what this is for.
TEST_F(ReactionTest, ReactionCanExist) { // First argument is test group, second is test name
// Would crash if we couldn't instantiate a reaction.
}

TEST_F(ReactionTest, ReactionCanHaveRate) { // Rate test name
  emptyReaction.AddRate(0.1);
  EXPECT_EQ(emptyReaction.GetRate(),0.1);
}

// Test that the system has a name as expected.
TEST_F(ReactionTest, ReactionCanHaveReactant) {
  emptyReaction.AddReactant(calcium);
  EXPECT_EQ(emptyReaction.GetReactants()[0].GetName(),"Ca");
}

TEST_F(ReactionTest, ReactionCanHaveMultipleReactants) {
  emptyReaction.AddReactant(calcium);
  emptyReaction.AddReactant(carbon);
  emptyReaction.AddReactant(oxygen);
  ASSERT_EQ(emptyReaction.GetReactants().size(),3)
  EXPECT_EQ(emptyReaction.GetReactants()[0].GetName(),"Ca");
}

TEST_F(ReactionTest, ReactionCanHaveProduct) {
  emptyReaction.AddProduct(calcium_carbonate);
  EXPECT_EQ(emptyReaction.GetProducts()[0].GetName(),"CaC03");
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
