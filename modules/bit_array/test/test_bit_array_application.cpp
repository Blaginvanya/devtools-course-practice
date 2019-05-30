// Copyright 2019 Muravev Denis

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/bit_array_application.h"

using ::testing::internal::RE;

class BitArrayApplicationTest : public ::testing::Test {
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
     BitArrayApplication app_;
     std::string output_;
};

TEST_F(BitArrayApplicationTest, Can_Show_Help) {
    // Arrange
    std::vector<std::string> args = { "help" };

    // Act
    Act(args);

    // Assert
    Assert("This is a bit array application\\..*");
}

TEST_F(BitArrayApplicationTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    std::vector<std::string> args = {"1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: There must be at least 4 arguments\\..*");
}

TEST_F(BitArrayApplicationTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    std::vector<std::string> args = {"q", "111", "d", "1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong operation format!");
}

TEST_F(BitArrayApplicationTest, Can_Create_And_Add) {
    // Arrange
    std::vector<std::string> args = { "c", "4", "a", "1", "3" };

    // Act
    Act(args);

    // Assert
    Assert("Res bit array = 0101");
}

TEST_F(BitArrayApplicationTest, Can_Modify_And_Add) {
    // Arrange
    std::vector<std::string> args = { "m", "0000", "a", "1", "3" };

    // Act
    Act(args);

    // Assert
    Assert("Res bit array = 0101");
}

TEST_F(BitArrayApplicationTest, Can_Create_And_Del) {
    // Arrange
    std::vector<std::string> args = { "c", "4", "d", "1", "3" };

    // Act
    Act(args);

    // Assert
    Assert("Res bit array = 0000");
}

TEST_F(BitArrayApplicationTest, Can_Modify_And_Del) {
    // Arrange
    std::vector<std::string> args = { "m", "0111", "d", "1", "3" };

    // Act
    Act(args);

    // Assert
    Assert("Res bit array = 0010");
}
