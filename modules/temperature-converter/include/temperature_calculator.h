// Copyright 2019 Ivan Yunin

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CALCULATOR_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CALCULATOR_H_

#include <string>

class TemperatureCalculator {
 public:
    TemperatureCalculator() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArgs(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CALCULATOR_H_
