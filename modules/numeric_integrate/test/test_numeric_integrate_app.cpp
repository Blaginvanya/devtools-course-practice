// Copyright 2019 Vdovin Eugene

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/numeric_integrate_app.h"

using ::testing::internal::RE;

class NumericIntegrateAppTest : public ::testing::Test {
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
         std::cout << std::endl << output_ << std::endl;
     }

      void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
     }

 private:
     NumericIntegrateApp app_;
     std::string output_;
};

TEST_F(NumericIntegrateAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

     Act(args);

     Assert("This is a numeric integrate application\\..*");
}

TEST_F(NumericIntegrateAppTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(NumericIntegrateAppTest, Can_Detect_Wrong_Number_Format_1) {
    std::vector<std::string> args = {"1", "pi", "64", "rectangle"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(NumericIntegrateAppTest, Can_Detect_Wrong_Number_Format_2) {
    std::vector<std::string> args = {"1", "2", "pi", "rectangle"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(NumericIntegrateAppTest, Can_Detect_Wrong_Method_Format) {
    std::vector<std::string> args = {"1", "2", "64", "com"};

    Act(args);

    Assert("Wrong method format!");
}

TEST_F(NumericIntegrateAppTest, Can_Use_Rectangle_Method) {
    std::vector<std::string> args = {"1", "2", "5", "rectangle"};

    Act(args);

    Assert("Result = 1.21919");
}

TEST_F(NumericIntegrateAppTest, Can_Use_Trapezium_Method) {
    std::vector<std::string> args = {"1", "2", "5", "trapezium"};

    Act(args);

    Assert("Result = 1.21846");
}
