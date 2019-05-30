// Copyright 2019 Vikhrev Ivan

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/InterpolationSearchApplication.h"

class InterpolationSearchApplicationTest
    : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> parameters;
        parameters.push_back("interpolation-searh.exe");
        for (size_t i = 0; i < args_.size(); ++i) {
            parameters.push_back(args_[i].c_str());
        }

        const char** argv = &parameters.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) { EXPECT_EQ(expected, output_); }

 private:
    InterpolationSearchApplication app_;
    std::string output_;
};


TEST_F(InterpolationSearchApplicationTest,
         print_help_message_with_empty_arguments) {
    // Arrange
    std::vector<std::string> args = {};
    std::string output =
      "This is a demo app for demonstrating interpolation search.\n"
      "Application works only with sorted arrays of integers.\n"
      "You should specify next agruments:\n"
      "<path to file with array> <number of integers> <integer to find>\n"
      "Application returns index of required number.\n";
    // Act
    Act(args);
    // Assert
    Assert(output);
}

TEST_F(InterpolationSearchApplicationTest,
           print_error_message_when_cant_open_file) {
    // Arrange
    std::vector<std::string> args = {"path.txt", "14", "1"};
    std::string output = "Can't open file\n";
    // Act
    Act(args);
    // Assert
    Assert(output);
}

TEST_F(InterpolationSearchApplicationTest,
           print_index_when_find_number) {
    // Arrange
    std::vector<std::string> args = { "test_data.txt", "14", "1" };
    std::string output = "Index of required number is 1\n";
    // Act
    Act(args);
    // Assert
    Assert(output);
}

TEST_F(InterpolationSearchApplicationTest,
    print_message_when_cant_find_number) {
    // Arrange
    std::vector<std::string> args = { "test_data.txt", "14", "5" };
    std::string output = "Required number isn't found\n";
    // Act
    Act(args);
    // Assert
    Assert(output);
}
