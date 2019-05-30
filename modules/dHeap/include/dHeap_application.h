// Copyright 2019 Tolstikov Maksim

#ifndef MODULES_DHEAP_INCLUDE_DHEAP_APPLICATION_H_
#define MODULES_DHEAP_INCLUDE_DHEAP_APPLICATION_H_

#include <string>
#include <vector>

class DHeapApp {
 public:
    DHeapApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int d_;
        std::vector<int> weight_;
        char operation;
    } Arguments;
};

#endif  // MODULES_DHEAP_INCLUDE_DHEAP_APPLICATION_H_
