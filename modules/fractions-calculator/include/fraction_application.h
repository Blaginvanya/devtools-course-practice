// Copyright 2019 Andronov Maxim

#ifndef MODULES_FRACTIONS_CALCULATOR_INCLUDE_FRACTION_APPLICATION_H_
#define MODULES_FRACTIONS_CALCULATOR_INCLUDE_FRACTION_APPLICATION_H_

#include <string>

class FractionCalculator {
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int f1_num;
        int f1_den;
        int f2_num;
        int f2_den;
        char operation;
    } Arguments;

 public:
    FractionCalculator() = default;
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_FRACTIONS_CALCULATOR_INCLUDE_FRACTION_APPLICATION_H_
