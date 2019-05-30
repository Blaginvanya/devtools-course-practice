// Copyright 2019 Karasev Anton

#ifndef MODULES_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_APPLICATION_H__
#define MODULES_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_APPLICATION_H__

#include <string>
#include <vector>

#include "include/fibonacci_heap.h"

class FibonacciHeapApplication {
 public:
    FibonacciHeapApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool valNumOfArg(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<int> weights_;
        char operation_;
    } Arguments;
};

#endif  // MODULES_FIBONACCI_HEAP_INCLUDE_FIBONACCI_HEAP_APPLICATION_H__
