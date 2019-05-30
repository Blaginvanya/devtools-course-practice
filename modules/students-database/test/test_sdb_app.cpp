// Copyright 2019 Kudrin Matvey

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/sdb_app.h"

using ::testing::internal::RE;

class SdbTest : public ::testing::Test {
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

    void Expect_Throw(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        EXPECT_ANY_THROW(app_(argc, argv));
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    SdbApp app_;
    std::string output_;
};

TEST_F(SdbTest, Returns_Empty_If_No_Args) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("");
}

TEST_F(SdbTest, Removes_Student) {
    std::vector<std::string> args = {"remove", "Kudrin"};

    Act(args);

    Assert("Student Kudrin removed");
}

TEST_F(SdbTest, Average_Mark_For_Student) {
    std::vector<std::string> args = {"average", "Kudrin"};

    Act(args);

    Assert("Average mark: -1");
}

TEST_F(SdbTest, Adds_Student) {
    std::vector<std::string> args = {"add", "Matvey", "Kudrin"};

    Act(args);

    Assert("Student Kudrin added");
}

TEST_F(SdbTest, Marks_Student) {
    std::vector<std::string> args = {"mark", "Kudrin", "mathematics", "5"};

    Act(args);

    Assert("Mark 5 was added to Kudrin");
}

TEST_F(SdbTest, Invalid_Metric) {
    std::vector<std::string> args = {"invalid"};

    Expect_Throw(args);
}

TEST_F(SdbTest, Incompatible_Number_Of_Args_And_Operation) {
    std::vector<std::string> args = {"add"};
    Expect_Throw(args);
    args = {"good", "boi"};
    Expect_Throw(args);
    args = {"bad", "boi", "girl"};
    Expect_Throw(args);
    args = {"good", "boi", "1", "2"};
    Expect_Throw(args);
}

TEST_F(SdbTest, Invalid_Number_Of_Args) {
    std::vector<std::string> args = {"good", "boi", "1", "2", "3"};

    Expect_Throw(args);
}



TEST_F(SdbTest, Get_Good_Students) {
    std::vector<std::string> args = {"good"};

    Act(args);

    Assert("Number of good students: 0");
}
TEST_F(SdbTest, Get_Bad_Students) {
    std::vector<std::string> args = {"bad"};

    Act(args);

    Assert("Number of bad students: 0");
}
TEST_F(SdbTest, Get_Total_Students) {
    std::vector<std::string> args = {"total"};

    Act(args);

    Assert("Number of students: 0");
}
