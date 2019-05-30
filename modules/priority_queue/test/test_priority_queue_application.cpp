// Copyright 2019 Bykovskaya Alina
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/priority-queue-application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class PriorAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("PriorityAppliction");
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
    PriorityApp app_;
    string output_;
};

TEST_F(PriorAppTest, Print_Help_If_No_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a priority queue application.\n\n*");
}

TEST_F(PriorAppTest, Can_Push_And_Top) {
    vector<string> args = {"push", "1", "2", "top"};

    Act(args);

    Assert("top element: 2");
}

TEST_F(PriorAppTest, Can_Push_And_Pop) {
    vector<string> args = { "push", "1", "2", "pop" };

    Act(args);

    Assert("");
}

TEST_F(PriorAppTest, Can_Push_Pop_And_Top_Right_Order) {
    vector<string> args = { "push", "1", "2", "push", "2", "3", "pop", "top" };

    Act(args);

    Assert("top element: 2");
}

TEST_F(PriorAppTest, Cant_Work_With_Wrong_Args) {
    vector<string> args = { "pu", "1", "2", "top" };

    Act(args);

    Assert("Wrong arguments!");
}
