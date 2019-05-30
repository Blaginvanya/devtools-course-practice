// Copyright 2019 Bykovskaya Alina
#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APPLICATION_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APPLICATION_H_

#include <string>
#include "include/priority_queue.h"

class PriorityApp {
 private:
    PriorityQueue q;
    std::string message_;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    int ParseOperation(const char** s);
 public:
    PriorityApp() = default;
    std::string operator()(int argc, const char **argv);
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APPLICATION_H_
