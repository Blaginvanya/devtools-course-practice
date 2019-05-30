// Copyright 2019 Kasmazyuk Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/mass_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MassCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

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
    MassCalculator app_;
    string output_;
};

TEST_F(MassCalculatorTest, Can_Print_Advice_For_User_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a mass calculator application\\..*");
}

TEST_F(MassCalculatorTest, Can_Check_Number_Of_Arguments) {
    vector<string> args = {"5.5"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(MassCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"two", "TonsToKilograms"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(MassCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(MassCalculatorTest, Can_Tons_To_Grams) {
    vector<string> args = {"0.001", "TonsToGrams"};

    Act(args);

    Assert("Grams: 1000");
}

TEST_F(MassCalculatorTest, Can_Tons_To_Pounds) {
    vector<string> args = {"10.0", "TonsToPounds"};

    Act(args);

    Assert("Pounds: 22046");
}

TEST_F(MassCalculatorTest, Can_Tons_To_Kilograms) {
    vector<string> args = {"1.0", "TonsToKilograms"};

    Act(args);

    Assert("Kilograms: 1000");
}

TEST_F(MassCalculatorTest, Can_Tons_To_Milligrams) {
    vector<string> args = {"0.000001", "TonsToMilligrams"};

    Act(args);

    Assert("Milligrams: 1000");
}

TEST_F(MassCalculatorTest, Can_Tons_To_Ounces) {
    vector<string> args = {"35274.962", "TonsToOunces"};

    Act(args);

    Assert("Ounces: 1");
}

TEST_F(MassCalculatorTest, Can_Grams_To_Ounces) {
    vector<string> args = {"28.35", "GramsToOunces"};

    Act(args);

    Assert("Ounces: 1");
}

TEST_F(MassCalculatorTest, Can_Grams_To_Pounds) {
    vector<string> args = {"453.592", "GramsToPounds"};

    Act(args);

    Assert("Pounds: 1");
}

TEST_F(MassCalculatorTest, Can_Grams_To_Milligrams) {
    vector<string> args = {"1.0", "GramsToMilligrams"};

    Act(args);

    Assert("Milligrams: 1000");
}

TEST_F(MassCalculatorTest, Can_Grams_To_Tons) {
    vector<string> args = {"1000000.0", "GramsToTons"};

    Act(args);

    Assert("Tons: 1");
}

TEST_F(MassCalculatorTest, Can_Grams_To_Kilograms) {
    vector<string> args = {"1000.0", "GramsToKilograms"};

    Act(args);

    Assert("Kilograms: 1");
}

TEST_F(MassCalculatorTest, Can_Kilograms_To_Grams) {
    vector<string> args = {"1.0", "KilogramsToGrams"};

    Act(args);

    Assert("Grams: 1000");
}

TEST_F(MassCalculatorTest, Can_Kilograms_To_Tons) {
    vector<string> args = {"1000.0", "KilogramsToTons"};

    Act(args);

    Assert("Tons: 1");
}

TEST_F(MassCalculatorTest, Can_Kilograms_To_Milligrams) {
    vector<string> args = {"0.001", "KilogramsToMilligrams"};

    Act(args);

    Assert("Milligrams: 1000");
}

TEST_F(MassCalculatorTest, Can_Kilograms_To_Pounds) {
    vector<string> args = {"1.0", "KilogramsToPounds"};

    Act(args);

    Assert("Pounds: 2.205");
}

TEST_F(MassCalculatorTest, Can_Kilograms_To_Ounces) {
    vector<string> args = {"1.0", "KilogramsToOunces"};

    Act(args);

    Assert("Ounces: 35.274");
}

TEST_F(MassCalculatorTest, Can_Milligrams_To_Pounds) {
    vector<string> args = {"453592.37", "MilligramsToPounds"};

    Act(args);

    Assert("Pounds: 1");
}

TEST_F(MassCalculatorTest, Can_Milligrams_To_Ounces) {
    vector<string> args = {"28349.523", "MilligramsToOunces"};

    Act(args);

    Assert("Ounces: 1");
}

TEST_F(MassCalculatorTest, Can_Milligrams_To_Tons) {
    vector<string> args = {"1000000000", "MilligramsToTons"};

    Act(args);

    Assert("Tons: 1");
}

TEST_F(MassCalculatorTest, Can_Milligrams_To_Kilograms) {
    vector<string> args = {"1000000.0", "MilligramsToKilograms"};

    Act(args);

    Assert("Kilograms: 1");
}

TEST_F(MassCalculatorTest, Can_Milligrams_To_Grams) {
    vector<string> args = {"1000.0", "MilligramsToGrams"};

    Act(args);

    Assert("Grams: 1");
}

TEST_F(MassCalculatorTest, Can_Ounces_To_Pounds) {
    vector<string> args = {"16.0", "OuncesToPounds"};

    Act(args);

    Assert("Pounds: 1");
}

TEST_F(MassCalculatorTest, Can_Ounces_To_Milligrams) {
    vector<string> args = {"1.0", "OuncesToMilligrams"};

    Act(args);

    Assert("Milligrams: 28349.5");
}

TEST_F(MassCalculatorTest, Can_Ounces_To_Grams) {
    vector<string> args = {"1.0", "OuncesToGrams"};

    Act(args);

    Assert("Grams: 28.35");
}

TEST_F(MassCalculatorTest, Can_Ounces_To_Tons) {
    vector<string> args = {"35273.962", "OuncesToTons"};

    Act(args);

    Assert("Tons: 1");
}

TEST_F(MassCalculatorTest, Can_Ounces_To_Kilograms) {
    vector<string> args = {"35.274", "OuncesToKilograms"};

    Act(args);

    Assert("Kilograms: 1");
}

TEST_F(MassCalculatorTest, Can_Pounds_To_Kilograms) {
    vector<string> args = {"2.205", "PoundsToKilograms"};

    Act(args);

    Assert("Kilograms: 1");
}

TEST_F(MassCalculatorTest, Can_Pounds_To_Grams) {
    vector<string> args = {"1.0", "PoundsToGrams"};

    Act(args);

    Assert("Grams: 453.592");
}

TEST_F(MassCalculatorTest, Can_Pounds_To_Tons) {
    vector<string> args = {"2204.623", "PoundsToTons"};

    Act(args);

    Assert("Tons: 1");
}

TEST_F(MassCalculatorTest, Can_Pounds_To_Ounces) {
    vector<string> args = {"1.0", "PoundsToOunces"};

    Act(args);

    Assert("Ounces: 16");
}

TEST_F(MassCalculatorTest, Can_Pounds_To_Milligrams) {
    vector<string> args = {"1.0", "PoundsToMilligrams"};

    Act(args);

    Assert("Milligrams: 453592");
}
