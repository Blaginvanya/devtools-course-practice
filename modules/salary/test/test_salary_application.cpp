// Copyright 2019 Ryabova Alyona

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/salary_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SalaryApplicationTest : public ::testing::Test {
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
    SalaryApplication app_;
    string output_;
};

TEST_F(SalaryApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a application for class salary\\..*");
}

TEST_F(SalaryApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "25000", "160" };

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"25000", "pi", "150", "5", "5"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Negative_Salary) {
    vector<string> args = {"-25000", "160", "150", "5", "5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Zero_Salary) {
    vector<string> args = {"0", "160", "150", "5", "5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Negative_Norm) {
    vector<string> args = {"25000", "-160", "150", "5", "5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Zero_Norm) {
    vector<string> args = {"25000", "0", "150", "5", "5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Negative_Worked_Hours) {
    vector<string> args = {"25000", "160", "-150", "5", "5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Negative_Overtime) {
    vector<string> args = {"25000", "160", "150", "-5", "5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Detect_Negative_Vacantion) {
    vector<string> args = {"25000", "160", "150", "5", "-5"};

    Act(args);

    Assert("Invalid value.*");
}

TEST_F(SalaryApplicationTest, Can_Calculate_Salary) {
    std::vector<std::string> args = {"25000", "160", "150", "5", "5"};

    Act(args);

    Assert("23437.5");
}

TEST_F(SalaryApplicationTest, Can_Detect_Wrong_Overflow) {
    std::vector<std::string> args = {"25000", "160",
        "7234345435636634", "5", "5"};

     Act(args);

     Assert("Number is out of bounds");
}
