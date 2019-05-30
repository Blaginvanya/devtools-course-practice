// Copyright 2019 Gribanov Mihail

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APPLICATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APPLICATION_H_

#include <include/quadratic_equation.h>

#include <string>
#include <array>
class QuadraticEquationApplication {
 public:
     QuadraticEquationApplication() = default;
     std::string operator()(int argc, const char** argv);

 private:
     std::string message_;
     std::array<int, 3> coef;
     void Help(const char* appname, const char* message = "");
     bool CheckArguments(int argc, const char** argv);
};
#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APPLICATION_H_
