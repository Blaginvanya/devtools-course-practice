// Copyright 2019 Druzhinin Alexei

#ifndef MODULES_SEARCH_BINARY_INCLUDE_SEARCH_BINARY_APPLICATION_H_
#define MODULES_SEARCH_BINARY_INCLUDE_SEARCH_BINARY_APPLICATION_H_

#include <string>
#include "include/search_binary.h"

class SearchBinaryApplication {
 private:
    std::string message_;
    int size;
    int item;
    int *array;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
 public:
    SearchBinaryApplication();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_SEARCH_BINARY_INCLUDE_SEARCH_BINARY_APPLICATION_H_
