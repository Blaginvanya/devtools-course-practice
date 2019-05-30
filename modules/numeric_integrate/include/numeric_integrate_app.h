// Copyright 2019 Vdovin Eugene

#ifndef MODULES_NUMERIC_INTEGRATE_INCLUDE_NUMERIC_INTEGRATE_APP_H_
#define MODULES_NUMERIC_INTEGRATE_INCLUDE_NUMERIC_INTEGRATE_APP_H_

#include <string>

class NumericIntegrateApp {
 public:
    NumericIntegrateApp();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double a;
        double b;
        int n;
        int method;
    } Arguments;
};

#endif  // MODULES_NUMERIC_INTEGRATE_INCLUDE_NUMERIC_INTEGRATE_APP_H_
