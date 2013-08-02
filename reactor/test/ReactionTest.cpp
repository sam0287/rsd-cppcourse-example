#include "Reaction.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

// Test that the system has a name as expected.
TEST(ReactionTest, ReactionHasAName) { // First argument is test group, second is test name
  Reaction myReaction("SomeName"); // Create a reaction with a specified name
  EXPECT_EQ("SomeName", myReaction.GetName()); // Assert that the name should be as expected
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}