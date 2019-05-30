// Copyright 2019 Sitkin Dmitry

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/calculator.h"

using ::testing::internal::RE;

class CalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
        std::cout << std::endl << output_ << std::endl;
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Calculator app_;
    std::string output_;
};

TEST_F(CalculatorTest, Returns_Empty_If_No_Args) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("");
}

TEST_F(CalculatorTest, Returns_Empty_If_Not_Four_Args) {
    std::vector<std::string> args = { "10000", "1" };

    Act(args);

    Assert("");
}

TEST_F(CalculatorTest, Returns_Empty_If_Wrong_Args) {
    std::vector<std::string> args = { "10000", "1", "q", "?" };

    Act(args);

    Assert("");
}

TEST_F(CalculatorTest, Can_Calculate_Final_Amount) {
    std::vector<std::string> args = { "10000", "0", "12", "10" };

    Act(args);

    Assert("879");
}
