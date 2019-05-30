// Copyright 2019 Tolstikov Maksim

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/dHeap_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DHeapAppTest : public ::testing::Test {
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
    DHeapApp app_;
    string output_;
};

TEST_F(DHeapAppTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is dHeap application\\..*");
}

TEST_F(DHeapAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "2", "pi", "4", "min"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(DHeapAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "2", "1", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(DHeapAppTest, Can_Sort_DHeap) {
    vector<string> args = { "2", "4", "1", "4", "2", "3", "sort" };

    Act(args);

    Assert("Weight = 1 2 3 4");
}

TEST_F(DHeapAppTest, Can_Find_Minimum_In_DHeap) {
    vector<string> args = { "2", "4", "1", "4", "2", "3", "min" };

    Act(args);

    Assert("Min = 1");
}

TEST_F(DHeapAppTest, Can_Find_Maximum_In_DHeap) {
    vector<string> args = { "2", "4", "1", "4", "2", "3", "max" };

    Act(args);

    Assert("Max = 4");
}
