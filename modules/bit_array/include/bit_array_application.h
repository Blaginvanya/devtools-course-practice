// Copyright 2019 Muravev Denis

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_

#include "include/bit_array.h"

#include <string>
#include <vector>

class BitArrayApplication {
 public:
    BitArrayApplication();
    std::string operator()(int argc, const char** argv);

 private:
     void Help(const char* appname, const char* message = "");
     bool ValidateArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        char type_data;
        std::string data;
        char operation;
        std::vector<int> set_value;
    } Arguments;
};

#endif  // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_APPLICATION_H_
