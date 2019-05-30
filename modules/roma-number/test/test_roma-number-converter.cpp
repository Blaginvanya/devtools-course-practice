// Copyright 2019 Pinaev Danil

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/romanumber_converter.h"

class RomaNumberConverterTest :
    public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
            ::testing::internal::RE(expected)));
    }

 private:
    RomaNumberConverter app_;
    std::string output_;
};

TEST_F(RomaNumberConverterTest, Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for roma number converter.");
}

TEST_F(RomaNumberConverterTest, Print_Help_With_Wrong_Lines_Count) {
    std::vector<std::string> args = { "CCCXXIV", "V" };

    Act(args);

    Assert("This is application for roma number converter.");
}

TEST_F(RomaNumberConverterTest, Print_Help_With_Wrong_Value) {
    std::vector<std::string> args = { "@#fd" };

    Act(args);

    Assert("This is application for roma number converter.");
}

TEST_F(RomaNumberConverterTest, Can_Convert_Arabic_To_Roma) {
    std::vector<std::string> args = {"324"};

    Act(args);

    Assert("CCCXXIV");
}

TEST_F(RomaNumberConverterTest, Can_Convert_Roma_To_Arabic) {
    std::vector<std::string> args = { "CCCXXIV" };

    Act(args);

    Assert("324");
}
