// Copyright 2019 Ivan Yunin

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/temperature_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TemperatureCalculatorTest : public ::testing::Test {
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
    TemperatureCalculator app_;
    string output_;
};

TEST_F(TemperatureCalculatorTest, Can_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a temperature calculator application\\..*");
}

TEST_F(TemperatureCalculatorTest, Can_Check_Number_Of_Arguments) {
    // Arrange
    vector<string> args = {"273.0"};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(TemperatureCalculatorTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = {"five", "CelsiusToKelvin"};
    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!.*");
}

TEST_F(TemperatureCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    vector<string> args = {"1.5", "Operation"};
    // Act
    Act(args);
    // Assert
    Assert("Wrong operation format!");
}

TEST_F(TemperatureCalculatorTest, Celsius_To_Fahrenheit) {
    // Arrange
    vector<string> args = {"0.0", "CelsiusToFahrenheit"};
    // Act
    Act(args);
    // Assert
    Assert("Fahrenheit: 32");
}

TEST_F(TemperatureCalculatorTest, Fahrenheit_To_Celsius) {
    // Arrange
    vector<string> args = {"5.0", "FahrenheitToCelsius"};
    // Act
    Act(args);
    // Assert
    Assert("Celsius: -15");
}

TEST_F(TemperatureCalculatorTest, Kelvin_To_Celsius) {
    // Arrange
    vector<string> args = {"0.0", "KelvinToCelsius"};
    // Act
    Act(args);
    // Assert
    Assert("Celsius: -273.15");
}

TEST_F(TemperatureCalculatorTest, Celsius_To_Kelvin) {
    // Arrange
    vector<string> args = {"100.0", "CelsiusToKelvin"};
    // Act
    Act(args);
    // Assert
    Assert("Kelvin: 373.15");
}

TEST_F(TemperatureCalculatorTest, Celsius_To_Newton) {
    // Arrange
    vector<string> args = {"100.0", "CelsiusToNewton"};
    // Act
    Act(args);
    // Assert
    Assert("Newton: 33");
}

TEST_F(TemperatureCalculatorTest, Newton_To_Celsius) {
    // Arrange
    vector<string> args = {"33.0", "NewtonToCelsius"};
    // Act
    Act(args);
    // Assert
    Assert("Celsius: 100");
}
