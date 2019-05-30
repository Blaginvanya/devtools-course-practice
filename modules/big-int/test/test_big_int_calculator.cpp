// Copyright 2019 Volkov Pavel


#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/big_int_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;



class BigIntCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
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
    BigIntCalculator app_;
    string output_;
};

TEST_F(BigIntCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a big int number calculator application\\..*");
}

TEST_F(BigIntCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(BigIntCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "pi", "+"};

    Act(args);

    Assert("Wrong number format.*");
}

TEST_F(BigIntCalculatorTest, Can_Detect_Wrong_Number_Format_zero_length) {
    vector<string> args = {"-", "pi", "+"};

    Act(args);

    Assert("Wrong number format.*");
}

TEST_F(BigIntCalculatorTest, Can_Add_Big_Int) {
    vector<string> args = {"2000000000000000000000004",
                          "9000000000000000000000007", "+"};

    Act(args);

    Assert("Result = 11000000000000000000000011");
}

TEST_F(BigIntCalculatorTest, Can_Diff_Big_Int) {
    vector<string> args = {"2000000000000000000000004",
                           "2000000000000000000000005", "-"};

    Act(args);

    Assert("Result = -1");
}

TEST_F(BigIntCalculatorTest, Can_Mult_Big_Int) {
    vector<string> args = {"111111111", "-111111111", "*"};

    Act(args);

    Assert("Result = -12345678987654321");
}

TEST_F(BigIntCalculatorTest, Can_Divide_Big_Int) {
    vector<string> args = {"12345678987654321", "111111111", "/"};

    Act(args);

    Assert("Result = 111111111");
}

TEST_F(BigIntCalculatorTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = {"100", "0", "/"};

    Act(args);

    Assert("Can't divide by zero");
}
