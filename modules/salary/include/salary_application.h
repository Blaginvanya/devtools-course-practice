// Copyright 2019 Ryabova Alyona

#ifndef MODULES_SALARY_INCLUDE_SALARY_APPLICATION_H_
#define MODULES_SALARY_INCLUDE_SALARY_APPLICATION_H_

#include <string>

class SalaryApplication {
 public:
    SalaryApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int salary;
        int norm;
        int overtime;
        int vacantion;
        int worked_hours;
    } Arguments;
};

#endif  // MODULES_SALARY_INCLUDE_SALARY_APPLICATION_H_
