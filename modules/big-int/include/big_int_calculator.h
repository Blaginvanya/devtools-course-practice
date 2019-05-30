// Copyright 2019 Volkov Pavel

#ifndef MODULES_BIG_INT_INCLUDE_BIG_INT_CALCULATOR_H_
#define MODULES_BIG_INT_INCLUDE_BIG_INT_CALCULATOR_H_

#include <string>

class BigIntCalculator {
 public:
    BigIntCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string operand_1;
        std::string operand_2;
        char operation;
    } Arguments;
};

#endif  // MODULES_BIG_INT_INCLUDE_BIG_INT_CALCULATOR_H_
