// Copyright 2019 Likholat Ann

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/string_calculator_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class StringCalculatorAppTest : public ::testing::Test {
 protected:
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
    StringCalculatorApp app_;
    string output_;
};

TEST_F(StringCalculatorAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a string calculator application\\..*");
}

TEST_F(StringCalculatorAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1+1", "2+1"};

    Act(args);

    Assert("ERROR: Should be 1 argument\\..*");
}

TEST_F(StringCalculatorAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "pi+2" };

    Act(args);

    Assert("ERROR: Incorrect data");
}

TEST_F(StringCalculatorAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1++2" };

    Act(args);

    Assert("ERROR: Incorrect data");
}

TEST_F(StringCalculatorAppTest, Can_Detect_Wrong_String_Format) {
    vector<string> args = { "*2-3" };

    Act(args);

    Assert("ERROR: Incorrect data");
}

TEST_F(StringCalculatorAppTest, Can_Add_Two_Numbers) {
    vector<string> args = { "1.5+3.2"};

    Act(args);

    Assert("Result = 4.7");
}

TEST_F(StringCalculatorAppTest, Can_Diff_Two_Numbers) {
    vector<string> args = { "1.5-3.2" };

    Act(args);

    Assert("Result = -1.7");
}

TEST_F(StringCalculatorAppTest, Can_Mult_Two_Numbers) {
    vector<string> args = { "1.5*3.2" };

    Act(args);

    Assert("Result = 4.8");
}

TEST_F(StringCalculatorAppTest, Can_Divide_Two_Numbers) {
    vector<string> args = { "3.2/2" };

    Act(args);

    Assert("Result = 1.6");
}

TEST_F(StringCalculatorAppTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = { "1/0" };

    Act(args);

    Assert("ERROR: division by zero");
}

TEST_F(StringCalculatorAppTest, Can_Rase_To_A_Power) {
    vector<string> args = { "3^2" };

    Act(args);

    Assert("Result = 9");
}

TEST_F(StringCalculatorAppTest, Can_Do_Several_Operations) {
    vector<string> args = { "4*2-2^3/4" };

    Act(args);

    Assert("Result = 6");
}

TEST_F(StringCalculatorAppTest, Can_Not_Calculate_Mismatched_Brackets) {
    vector<string> args = { ")2+2(" };

    Act(args);

    Assert("ERROR: Incorrect data");
}

TEST_F(StringCalculatorAppTest, Can_Use_Brackets) {
    string str = "(1+1+1+1)";
    vector<string> args = { str };

    Act(args);

    Assert("Result = 4");
}

TEST_F(StringCalculatorAppTest, Can_Not_Calculate_Wrong_Num_Of_Brackets) {
    string str = "(((2+2)/3)";
    vector<string> args = { str };

    Act(args);

    Assert("ERROR: Incorrect data");
}
