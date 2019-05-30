// Copyright 2019 Gaydaychuk Yury

#ifndef MODULES_PRINT_SIMPLE_NUMBERS_INCLUDE_PRIME_COUNTER_H_
#define MODULES_PRINT_SIMPLE_NUMBERS_INCLUDE_PRIME_COUNTER_H_

#include <string>

class PrimeCounter {
 public:
    PrimeCounter();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int left_boundary;
        int right_boundary;
    } Arguments;
};

#endif  // MODULES_PRINT_SIMPLE_NUMBERS_INCLUDE_PRIME_COUNTER_H_
