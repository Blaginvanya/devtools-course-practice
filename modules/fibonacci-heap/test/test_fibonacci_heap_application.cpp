// Copyright 2019 Karasev Anton

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>

#include "include/fibonacci_heap_application.h"

using ::testing::internal::RE;

class FibonacciHeapApplicationTest : public ::testing::Test {
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
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
     FibonacciHeapApplication app_;
     std::string output_;
};

TEST_F(FibonacciHeapApplicationTest, Can_Show_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a fibonacci heap application\\..*");
}

TEST_F(FibonacciHeapApplicationTest, Check_Number_Of_Arguments) {
    // Arrange
    std::vector<std::string> args = {"min", "1"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: There must be at least 4 arguments\\..*");
}

TEST_F(FibonacciHeapApplicationTest, Can_Detecting_Wrong_Operation_Format) {
    // Arrange
    std::vector<std::string> args = {"T", "1", "2", "3"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong operation format!");
}

TEST_F(FibonacciHeapApplicationTest, Can_Find_Min_In_Heap) {
    // Arrange
    std::vector<std::string> args = {"min", "1", "2", "3"};

    // Act
    Act(args);

    // Assert
    Assert("Min = 2");
}

TEST_F(FibonacciHeapApplicationTest, Can_Find_Elem_For_Key_In_Heap) {
    // Arrange
    std::vector<std::string> args = {"find", "1", "1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("1 is found in heap");
}

TEST_F(FibonacciHeapApplicationTest, Can_Not_Find_Elem_For_Key_In_Heap) {
    // Arrange
    std::vector<std::string> args = {"find", "1", "2", "3"};

    // Act
    Act(args);

    // Assert
    Assert("1 not found in heap");
}

TEST_F(FibonacciHeapApplicationTest, Can_Merge_In_Heap) {
    // Arrange
    std::vector<std::string> args = {"merge", "1", "1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("Merge successfully");
}
