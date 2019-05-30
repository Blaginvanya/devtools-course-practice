// Copyright 2019 Zhivaev Artem

#ifndef MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBERSYSTEMSAPP_H_
#define MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBERSYSTEMSAPP_H_

#include <string>

#include "include/NumberSystemsConverter.h"

class NumberSystemsApp {
 public:
    NumberSystemsApp() = default;
    std::string operator()(int argc, const char **agv);

 private:
    void Help(const char *appname, const char *message = "");
    bool ValidateNumberOfArgs(int argc, const char **argv);
    std::string message_;
    typedef struct {
        std::string number;
        SysBase sb1;
        SysBase sb2;
    } Arguments;
};

#endif  //  MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBERSYSTEMSAPP_H_

