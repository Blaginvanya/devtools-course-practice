// Copyright 2019 Utkin Konstantin

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/queue_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QueueApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("QueueApplication");
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
    QueueApplication app_;
    string output_;
};

TEST_F(QueueApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a queue application\\..*");
}

TEST_F(QueueApplicationTest, Can_Put) {
    vector<string> args = { "put", "6243" };

    Act(args);

    Assert("");
}

TEST_F(QueueApplicationTest, Can_Put_Several_Times) {
    vector<string> args = { "put", "33", "put", "44", "put", "-1" };

    Act(args);

    Assert("");
}

TEST_F(QueueApplicationTest, Can_Get) {
    vector<string> args = { "put", "201", "get" };

    Act(args);

    Assert("Gotten element = 201");
}

TEST_F(QueueApplicationTest, Can_Top) {
    vector<string> args = { "put", "-23445", "top" };

    Act(args);

    Assert("The top element = -23445");
}

TEST_F(QueueApplicationTest, Can_Get_Several_Times) {
    vector<string> args = { "put", "1", "put", "-2", "get", "get"};

    Act(args);

    Assert("Gotten element = -2");
}

TEST_F(QueueApplicationTest, Can_Top_Several_Times) {
    vector<string> args = { "put", "-1", "put", "2", "top", "top" };

    Act(args);

    Assert("The top element = -1");
}

TEST_F(QueueApplicationTest, Can_Detect_Wrong_Format_Of_Operations) {
    vector<string> args = { "put", "100", "Push", "2", "top" };

    Act(args);

    Assert("Argument error");
}
