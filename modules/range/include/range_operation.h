// Copyright 2019 Sadikov Artem

#ifndef MODULES_RANGE_INCLUDE_RANGE_OPERATION_H_
#define MODULES_RANGE_INCLUDE_RANGE_OPERATION_H_

#include <string>

class RangeOperation {
 public:
    RangeOperation();
    std::string operator()(int argc, const char** argv);
    int parseOperation(const char* arg, int argc);

 private:
    void help(const char* appname, const char* message = "");
    std::string message_;
    int op;
};

#endif  // MODULES_RANGE_INCLUDE_RANGE_OPERATION_H_
