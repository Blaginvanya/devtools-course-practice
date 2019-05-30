// Copyright 2019 Likholat Ann

#ifndef MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
#define MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
#include <string>

class StringCalculatorApp {
 public:
    StringCalculatorApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    std::string expression_;
};

#endif  // MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_APP_H_
