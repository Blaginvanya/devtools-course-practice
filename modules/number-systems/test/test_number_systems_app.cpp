// Copyright 2019 Zhivaev Artem

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/NumberSystemsApp.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumberSystemsTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("number system");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    NumberSystemsApp app_;
    string output_;
};

TEST_F(NumberSystemsTest, Do_Print_Help_Without_Args) {
    vector<string> args = {};

    Act(args);

    Assert("This is a number systems converter\\..*");
}

TEST_F(NumberSystemsTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(NumberSystemsTest, Can_Detect_Wrong_System_Base_Format) {
    vector<string> args = {"2037465", "OCT", "BEN"};

    Act(args);

    Assert("Wrong system base format!.*");
}

TEST_F(NumberSystemsTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"8", "OCT", "HEX"};

    Act(args);

    Assert("Wrong oct_digit switch.*");
}

TEST_F(NumberSystemsTest, Convert_Bin_To_Hex) {
    vector<string> args = {"1111", "BIN", "HEX"};

    Act(args);

    Assert("BIN: 1111\nHEX: F.*");
}

TEST_F(NumberSystemsTest, Convert_Hex_To_Bin) {
    vector<string> args = {"F", "HEX", "BIN"};

    Act(args);

    Assert("HEX: F\nBIN: 1111.*");
}

TEST_F(NumberSystemsTest, Convert_Oct_To_Oct) {
    vector<string> args = {"7", "OCT", "OCT"};

    Act(args);

    Assert("OCT: 7\nOCT: 7.*");
}

