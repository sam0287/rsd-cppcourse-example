#include "ReactionSystem.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

// Test that the system has a name as expected.
TEST(ReactionSystemTest, ReactionSystemConstructor) { // First argument is test group, second is test name
  ReactionSystem myReactionSystem; // Create a reactionsystem with a specified name
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}