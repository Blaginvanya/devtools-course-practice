// Copyright 2019 Repin Vladimir

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/lcd_digits_application.h"

class LCDDigitsApplicationTest
    : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> parameters;
        parameters.push_back("LCD-Digits.exe");
        for (size_t i = 0; i < args_.size(); ++i) {
            parameters.push_back(args_[i].c_str());
        }

        const char** argv = &parameters.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_EQ(expected, output_);
    }

 private:
    LCDDigitsApplication app_;
    std::string output_;
};

TEST_F(LCDDigitsApplicationTest, Can_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This application prints multiple strings in LCD format.\n\n"
        "Please provide arguments in the following format:\n\n"
        "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
        "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Throws_On_Single_Invalid_String_With_Letters) {
    std::vector<std::string> args = {"12.AB:2019"};

    Act(args);

    Assert("Invalid Symbol\n"
           "This application prints multiple strings in LCD format.\n\n"
           "Please provide arguments in the following format:\n\n"
           "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
           "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Throws_On_Single_Invalid_String_With_Symbols) {
    std::vector<std::string> args = { "06%^59" };

    Act(args);

    Assert("Invalid Symbol\n"
        "This application prints multiple strings in LCD format.\n\n"
        "Please provide arguments in the following format:\n\n"
        "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
        "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Throws_On_Multiple_Invalid_Strings) {
    std::vector<std::string> args = { "12", "ABC", "15:30", "db&"};

    Act(args);

    Assert("Invalid Symbol\n"
        "This application prints multiple strings in LCD format.\n\n"
        "Please provide arguments in the following format:\n\n"
        "  $ LCD-Digits.exe <str_1> <str_2> ... <str_n>\n"
        "Where str_i is string consisiting of digits, '.', ':'.\n");
}

TEST_F(LCDDigitsApplicationTest, Printing_All_Available_Symbols_Is_Correct) {
    std::vector<std::string> args = { "0123456789.:" };

    Act(args);

    Assert(" _     _   _       _   _   _   _   _      \n"
           "| | |  _|  _| |_| |_  |_    | |_| |_|   . \n"
           "|_| | |_   _|   |  _| |_|   | |_|  _| . . \n\n");
}

TEST_F(LCDDigitsApplicationTest, Printing_Single_Symbol_Is_Correct) {
    std::vector<std::string> args = { "1" };

    Act(args);

    Assert("  \n"
           "| \n"
           "| \n\n");
}

TEST_F(LCDDigitsApplicationTest, Printing_Multiple_Symbols_Is_Correct) {
    std::vector<std::string> args = { "06:59" };

    Act(args);

    Assert(" _   _     _   _  \n"
           "| | |_  . |_  |_| \n"
           "|_| |_| .  _|  _| \n\n");
}

TEST_F(LCDDigitsApplicationTest, Printing_Multiple_Strings_Is_Correct) {
    std::vector<std::string> args = { "59", "2.3" };

    Act(args);

    Assert(" _   _  \n"
           "|_  |_| \n"
           " _|  _| \n\n"
           " _     _  \n"
           " _|    _| \n"
           "|_  .  _| \n\n");
}

TEST_F(LCDDigitsApplicationTest, Printing_Without_Digits_Is_Correct) {
    std::vector<std::string> args = { "::.." };

    Act(args);

    Assert("        \n"
           ". .     \n"
           ". . . . \n\n");
}
