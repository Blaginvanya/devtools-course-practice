// Copyright 2019 Pinaev Danil

#ifndef MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_CONVERTER_H_
#define MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_CONVERTER_H_

#include <string>
#include "include/romanumber.h"

class RomaNumberConverter {
 public:
    RomaNumberConverter() = default;
    std::string operator()(int argc, const char** argv);

 private:
    std::string Help(const char* appname);
    bool validateNumberOfArguments(int argc, const char** argv);
    RomaNumber converter_;
    std::string message_;
    std::string value_;
};

#endif  // MODULES_ROMA_NUMBER_INCLUDE_ROMANUMBER_CONVERTER_H_
