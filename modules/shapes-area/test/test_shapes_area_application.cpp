// Copyright 2019 Evdokimov Artem

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/shapes_area_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;
class ShapesAreaApplicationTest :public::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("shapes-area");
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
    ShapesAreaApplication app_;
    std::string output_;
};

TEST_F(ShapesAreaApplicationTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("ShapesArea class application:");
}

TEST_F(ShapesAreaApplicationTest, Do_Print_Help_With_Arguments) {
    std::vector<std::string> args = {"help"};

    Act(args);

    Assert("ShapesArea class application:");
}

TEST_F(ShapesAreaApplicationTest, Check_Number_Of_Arguments_Tetrahedron) {
    vector<string> args = {"calc", "tetr"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesAreaApplicationTest, Check_Number_Of_Arguments_Parallelepiped) {
    vector<string> args = {"calc", "paral"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesAreaApplicationTest, Check_Number_Of_Arguments_Cone) {
    vector<string> args = {"calc", "cone"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesAreaApplicationTest, Check_Number_Of_Arguments_Cylinder) {
    vector<string> args = {"calc", "cylinder"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesAreaApplicationTest, Check_Number_Of_Arguments_Cube) {
    vector<string> args = {"calc", "cube"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesAreaApplicationTest, Check_Number_Of_Arguments_Sphere) {
    vector<string> args = {"calc", "sphere"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(ShapesAreaApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"calc", "paral", "2", "4", "pu"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Detect_Wrong_Param) {
    vector<string> args = {"calc", "nst", "2", "4", "5"};

    Act(args);

    Assert("wrong param.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Detect_Wrong_Command) {
    vector<string> args = {"fs", "paral", "2", "4", "5"};

    Act(args);

    Assert("wrong command.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Calculate_Cube_Area) {
    vector<string> args = {"calc", "cube", "2"};

    Act(args);

    Assert("area = 24.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Calculate_Cone_Area) {
    vector<string> args = {"calc", "cone", "2", "2"};

    Act(args);

    Assert("area = 25.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Calculate_Sphere_Area) {
    vector<string> args = {"calc", "sphere", "4"};

    Act(args);

    Assert("area = 201.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Calculate_Cylinder_Area) {
    vector<string> args = {"calc", "cylinder", "2", "2"};

    Act(args);

    Assert("area = 50.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Calculate_Parallelipiped_Area) {
    vector<string> args = {"calc", "paral", "5", "2" , "2"};

    Act(args);

    Assert("area = 48.*");
}

TEST_F(ShapesAreaApplicationTest, Can_Calculate_Tetrahedron_Area) {
    vector<string> args = {"calc", "tetr", "5"};

    Act(args);

    Assert("area = 43.*");
}
