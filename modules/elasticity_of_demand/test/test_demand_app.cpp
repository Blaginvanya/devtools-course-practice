// Copyright 2019 Yakovlev Pavel

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/demand_app.h"

using ::testing::internal::RE;

class DemandAppTest : public ::testing::Test {
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
     DemandApp app_;
     std::string output_;
};

TEST_F(DemandAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

     Act(args);

     Assert("This is a elasticity of demand application\\..*");
}

TEST_F(DemandAppTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 7 arguments\\..*");
}

TEST_F(DemandAppTest, Can_Detect_Wrong_Number_Format_double) {
    std::vector<std::string> args = {"1", "two", "3", "4", "5", "6", "i"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(DemandAppTest, Can_Detect_Wrong_Number_Format_int) {
    std::vector<std::string> args = {"1", "2", "three", "4", "5", "6", "i"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(DemandAppTest, Can_Detect_Wrong_Operation_Format) {
    std::vector<std::string> args = {"1", "2", "3", "4", "5", "6", "j"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(DemandAppTest, Can_Use_Price_Elasticity_Of_Demand) {
    std::vector<std::string> args = {"100", "140", "100", "60", "5", "6", "p"};

    Act(args);

    Assert("Result = -1.5");
}

TEST_F(DemandAppTest, Can_Use_Income_Elasticity_Of_Demand) {
    std::vector<std::string> args = {"1", "2", "100", "102",
        "10000", "10200", "i"};

    Act(args);

    Assert("Result = 1");
}

TEST_F(DemandAppTest, Can_Use_Cross_Elasticity_Of_Demand) {
    std::vector<std::string> args = {"100", "102", "100", "98", "5", "6", "c"};

    Act(args);

    Assert("Result = -1");
}
