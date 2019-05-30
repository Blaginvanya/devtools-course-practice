// Copyright 2019 Gribanov Mihail


#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/quadratic_equation_application.h"

class QuadraticEquationApplicationTest :
    public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
            ::testing::internal::RE(expected)));
    }

 private:
    QuadraticEquationApplication app_;
    std::string output_;
};

TEST_F(QuadraticEquationApplicationTest, Prints_Help_With_No_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a quadratic equation calculator application.");
}

TEST_F(QuadraticEquationApplicationTest,
Prints_Error_With_Wrong_Number_Of_Arguments) {
    std::vector<std::string> args = { "0", "0" };

    Act(args);

    Assert("ERROR: Should be 3 arguments.");
}

TEST_F(QuadraticEquationApplicationTest, Prints_Error_With_No_Solutions) {
    std::vector<std::string> args = { "5", "0", "30"};

    Act(args);

    Assert("No real solutions");
}

TEST_F(QuadraticEquationApplicationTest,
Prints_Error_With_Non_Quadratic_Equation) {
    std::vector<std::string> args = { "0", "0", "1" };

    Act(args);

    Assert("It is not a quadratic equation");
}

TEST_F(QuadraticEquationApplicationTest, Can_Solve_With_Two_Solutions) {
    std::vector<std::string> args = { "1", "-2", "-3" };

    Act(args);

    Assert("X1 = 3, X2 = -1");
}

TEST_F(QuadraticEquationApplicationTest, Can_Solve_With_One_Solution) {
    std::vector<std::string> args = { "1", "12", "36" };

    Act(args);

    Assert("X1 = X2 = -6");
}
