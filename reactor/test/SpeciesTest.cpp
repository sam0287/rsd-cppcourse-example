#include "Species.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

// Test that the system has a name as expected.
TEST(SpeciesTest, SystemHasAName) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a reaction system with a specified name
  EXPECT_EQ("SomeName", mySpecies.GetName()); // Assert that the name should be as expected
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}