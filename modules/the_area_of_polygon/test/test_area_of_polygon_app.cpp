// Copyright 2019 Dudchenko Anton

#include <vector>
#include <string>

#include "include/the_area_of_polygon_app.h"
#include "gtest/gtest.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AreaCalculatorTest : public ::testing::Test {
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
    AreaCalculator app_;
    string output_;
};

TEST_F(AreaCalculatorTest, Print_Info_Without_Args) {
    vector<string> vec = {};

    Act(vec);

    Assert("This is a area calculator application\\..*");
}

TEST_F(AreaCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> vec = {"0", "0", "1"};

    Act(vec);

    Assert("ERROR : Should be pass the points in the format <x y>\\..*");
}

TEST_F(AreaCalculatorTest, Is_Checking_Type_Of_Arguments) {
    vector<string> vec = { "0", "1", "/", "5" };

    Act(vec);

    Assert("ERROR : All arguments must be integers\\..*");
}

TEST_F(AreaCalculatorTest, Can_Calculate_Area) {
    vector<string> vec = { "0", "0", "0", "1", "1", "2", "1", "0" };

    Act(vec);

    Assert("Area of polygon = 1.50");
}
