// Copyright 2019 Fedotov Vlad

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/two_line_segments_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TwoLineSegmentsAppTest : public ::testing::Test {
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
    TwoLineSegmentsApp app_;
    string output_;
};

TEST_F(TwoLineSegmentsAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This application determines whether\\..*");
}

TEST_F(TwoLineSegmentsAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 8 arguments\\..*");
}

TEST_F(TwoLineSegmentsAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "pi", "2", "4", "5", "5", "6", "7" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(TwoLineSegmentsAppTest, Do_Intersecting_Segments_Intersect) {
    vector<string> args = { "1", "1", "4", "1", "2", "-1", "2", "3"};

    Act(args);

    Assert("These two line segments intersect!.*");
}

TEST_F(TwoLineSegmentsAppTest, Intersecting_Segments_DO_NOT_Intersect) {
    vector<string> args = { "1", "1", "4", "1", "1", "2", "4", "2" };

    Act(args);

    Assert("These two line segments DON'T intersect\\..*");
}
