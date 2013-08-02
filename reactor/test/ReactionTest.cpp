#include "Reaction.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

// Test that the system has a name as expected.
TEST(ReactionTest, ReactionConstructor) { // First argument is test group, second is test name
  Reaction myReaction(5.0); // Create a reaction with specified rate
  EXPECT_EQ(5.0, myReaction.GetRate()); // Assert that the name should be as expected
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}