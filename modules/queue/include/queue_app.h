// Copyright 2019 Utkin Konstantin

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <string>
#include "include/queue.h"

class QueueApplication {
 private:
    std::string message_;
    Queue que_;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    int ParseOperation(const char** s);
 public:
    QueueApplication() = default;
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
