#include "Species.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

// Test that the system has a name as expected.
TEST(SpeciesTest, SpeciesHasAName) { // First argument is test group, second is test name
  Species mySpecies("SomeName", 0.0); // Create a species with a specified name
  EXPECT_EQ("SomeName", mySpecies.GetName()); // Assert that the name should be as expected
}

// Test that the system has a concentration as expected.
TEST(SpeciesTest, SpeciesHasAConcentration) { // First argument is test group, second is test name
  Species mySpecies("SomeName", 0.1); // Create a species with a specified concentration
  EXPECT_FLOAT_EQ(0.0, mySpecies.GetConcentration()); // Assert that the concentration should be as expected
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
