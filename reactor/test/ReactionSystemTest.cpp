#include "ReactionSystem.h"
#include <gtest/gtest.h>

// Test that the system has a name as expected.
TEST(ReactionSystemTest, SystemHasAName) {
  ReactionSystem mySystem("SomeName");
  EXPECT_EQ("SomeName", mySystem.GetName());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}