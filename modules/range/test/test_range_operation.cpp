// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "../include/range_operation.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RangeOperationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("range");
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
    RangeOperation app_;
    string output_;
};

TEST_F(RangeOperationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a integer range application\\..*");
}

TEST_F(RangeOperationTest, Can_Detect_Wrong_Format_Contain_A) {
    vector<string> args = {"contain_a", "[34,100]"};

    Act(args);

    Assert("ERROR: Must be 3 args for contain_a");
}

TEST_F(RangeOperationTest, Contain_A_Work_By_True) {
    vector<string> args = {"contain_a", "[12,15]", "2", "12", "15"};

    Act(args);

    Assert("TRUE");
}

TEST_F(RangeOperationTest, Contain_A_Work_By_False) {
    vector<string> args = {"contain_a", "[12,15]", "2", "14", "16"};

    Act(args);

    Assert("FALSE");
}

TEST_F(RangeOperationTest, Detect_Wrong_Number_Format) {
    vector<string> args = {"contain_a", "[12,15]", "2", "pi", "15.2"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(RangeOperationTest, Can_Get_All_Points) {
    vector<string> args = {"all_p", "[12,15]"};

    Act(args);

    Assert("Points: 12, 13, 14, 15");
}

TEST_F(RangeOperationTest, Detect_Incorrect_Number_Of_Arguments_All_P) {
    vector<string> args = {"all_p"};

    Act(args);

    Assert("ERROR: Must be 2 args for all_p");
}

TEST_F(RangeOperationTest, Can_Check_Contain_Range_By_True) {
    vector<string> args = {"contain_r", "[12,16]", "(12,16)"};

    Act(args);

    Assert("TRUE");
}

TEST_F(RangeOperationTest, Can_Check_Contain_Range_By_False) {
    vector<string> args = {"contain_r", "[12,15]", "(10,12)"};

    Act(args);

    Assert("FALSE");
}

TEST_F(RangeOperationTest, Detect_Incorrect_Number_Of_Arguments_Contain_R) {
    vector<string> args = {"contain_r"};

    Act(args);

    Assert("ERROR: Must be 3 args for contain_r");
}

TEST_F(RangeOperationTest, Can_Get_End_Points) {
    vector<string> args = {"end_p", "[12,16]"};

    Act(args);

    Assert("Start: 12\nEnd: 16");
}

TEST_F(RangeOperationTest, Detect_Incorrect_Number_Of_Arguments_End_P) {
    vector<string> args = {"end_p"};

    Act(args);

    Assert("ERROR: Must be 2 args for end_p");
}

TEST_F(RangeOperationTest, Can_Check_Overlaps_By_True) {
    vector<string> args = {"overlap", "[12,16]", "(12,16)"};

    Act(args);

    Assert("TRUE");
}

TEST_F(RangeOperationTest, Can_Check_Overlaps_By_False) {
    vector<string> args = {"overlap", "[12,16]", "(10,12)"};

    Act(args);

    Assert("FALSE");
}

TEST_F(RangeOperationTest, Detect_Incorrect_Number_Of_Arguments_Overlap) {
    vector<string> args = {"overlap"};

    Act(args);

    Assert("ERROR: Must be 3 args for overlap");
}

TEST_F(RangeOperationTest, Can_Check_Equal_Ranges_By_True) {
    vector<string> args = {"equal", "[12,16]", "(11,17)"};

    Act(args);

    Assert("TRUE");
}

TEST_F(RangeOperationTest, Can_Check_Equal_Ranges_By_False) {
    vector<string> args = {"equal", "[12,16]", "(10,17)"};

    Act(args);

    Assert("FALSE");
}

TEST_F(RangeOperationTest, Detect_Incorrect_Number_Of_Arguments_Equal) {
    vector<string> args = {"equal"};

    Act(args);

    Assert("ERROR: Must be 3 args for equal");
}

TEST_F(RangeOperationTest, Detect_Wrong_Operation_Format) {
    vector<string> args = {"m-da"};

    Act(args);

    Assert("Wrong operation format!");
}
