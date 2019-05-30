// Copyright 2019 Andronov Maxim

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/fraction_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class FractionCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("FractionCalculator");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    FractionCalculator app_;
    string output_;
};

TEST_F(FractionCalculatorTest, Print_Help_If_No_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a fraction calculator application\\..*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "gh", "55", "qw", "584", "+" };

    Act(args);

    Assert("gh is not the number.*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1", "1", "1", "1", "gh" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Of_Arguments) {
    vector<string> args = { "1", "2", "+" };

    Act(args);

    Assert("ERROR: Should be 5 arguments.\n\n");
}

TEST_F(FractionCalculatorTest, Can_Add_Fractions) {
    vector<string> args = { "1", "2", "3", "4", "+" };

    Act(args);

    Assert("Numerator = 5 Denominator = 4");
}

TEST_F(FractionCalculatorTest, Can_Diff_Fractions) {
    vector<string> args = { "3", "4", "1", "2", "-" };

    Act(args);

    Assert("Numerator = 1 Denominator = 4");
}

TEST_F(FractionCalculatorTest, Can_Mult_Fractions) {
    vector<string> args = { "1", "2", "3", "4", "*" };

    Act(args);

    Assert("Numerator = 3 Denominator = 8");
}

TEST_F(FractionCalculatorTest, Can_Div_Fractions) {
    vector<string> args = { "1", "2", "3", "4", "/" };

    Act(args);

    Assert("Numerator = 2 Denominator = 3");
}



