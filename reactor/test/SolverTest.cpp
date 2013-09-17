#include "Solver.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

class SolverTest: public ::testing::Test {
public:
	std::istringstream system;
	std::ostringstream result;
	Solver solver;
	SolverTest():
		system("A > 2.0 > B\n"),result(),solver(system,result)
	{
	};
};

TEST_F(SolverTest, SolverCanParse) {
	EXPECT_EQ("Time: [A, B, ]\n",result.str());
}

TEST_F(SolverTest, SolverCanSolve) {
	solver.Solve(0,1.5,0.1);
	EXPECT_EQ("Time: [A, B, ]\n",result.str()); // Should fail
}

int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}