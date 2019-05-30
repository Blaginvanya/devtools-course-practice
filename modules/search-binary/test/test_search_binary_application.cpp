// Copyright 2019 Druzhinin Alexei

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/search_binary_application.h"

using ::testing::internal::RE;

class SearchBinaryApplicationTest : public ::testing::Test {
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
     SearchBinaryApplication app_;
     std::string output_;
};

TEST_F(SearchBinaryApplicationTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

     Act(args);

     Assert("This is a binary search application\\..*");
}

TEST_F(SearchBinaryApplicationTest, Is_Checking_Number_Of_Arguments) {
    std::vector<std::string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Check count of arguments and size of entered array\\..*");
}

TEST_F(SearchBinaryApplicationTest, Can_Detect_Wrong_Size_Of_Array) {
    std::vector<std::string> args = {"0", "2"};

    Act(args);

    Assert("ERROR: Size must be >= 1.*");
}

TEST_F(SearchBinaryApplicationTest,
    Is_Check_Entered_Size_And_Size_Of_Entered_Array) {
    std::vector<std::string> args = {"3", "2", "1", "2"};

    Act(args);

    Assert("ERROR: Check count of arguments and size of entered array\\..*");
}

TEST_F(SearchBinaryApplicationTest, Can_Detect_Wrong_Number_Format_In_Size) {
    std::vector<std::string> args = {"three", "2", "1", "2", "3"};

    Act(args);

    Assert("Wrong number format in size!.*");
}

TEST_F(SearchBinaryApplicationTest, Can_Detect_Wrong_Number_Format_In_Item) {
    std::vector<std::string> args = {"3", "two", "1", "2", "3"};

    Act(args);

    Assert("Wrong number format in item!.*");
}

TEST_F(SearchBinaryApplicationTest, Can_Detect_Wrong_Number_Format_In_Array) {
    std::vector<std::string> args = {"3", "2", "one", "2", "3"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(SearchBinaryApplicationTest, When_Item_Not_Found) {
    std::vector<std::string> args = {"3", "4", "1", "2", "3"};

    Act(args);

    Assert("Item not found.*");
}

TEST_F(SearchBinaryApplicationTest, Can_Detect_Unsorted_Array) {
    std::vector<std::string> args = {"3", "2", "3", "2", "1"};

    Act(args);

    Assert("Error! Array not sorted.*");
}

TEST_F(SearchBinaryApplicationTest, Can_Search_Item) {
    std::vector<std::string> args = {"3", "2", "1", "2", "3"};

    Act(args);

    Assert("Index of the item = 1");
}
