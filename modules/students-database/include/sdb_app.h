// Copyright 2019 Kudrin Matvey

#include <string>

#ifndef MODULES_STUDENTS_DATABASE_INCLUDE_SDB_APP_H_
#define MODULES_STUDENTS_DATABASE_INCLUDE_SDB_APP_H_

class SdbApp {
 public:
    SdbApp() = default;
    std::string operator()(int argc, const char** argv);
    std::string Help(const char* appname);

 private:
    std::string message_;
};

#endif  // MODULES_STUDENTS_DATABASE_INCLUDE_SDB_APP_H_
