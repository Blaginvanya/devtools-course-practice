// Copyright 2019 Kasmazyuk Nikita

#ifndef MODULES_MASS_CONVERTER_INCLUDE_MASS_CALCULATOR_H_
#define MODULES_MASS_CONVERTER_INCLUDE_MASS_CALCULATOR_H_

#include <string>

class MassCalculator {
 public:
    MassCalculator() = default;
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

#endif  // MODULES_MASS_CONVERTER_INCLUDE_MASS_CALCULATOR_H_
