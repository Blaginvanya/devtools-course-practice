// Copyright 2019 Gribanov Mihail

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

#include "include/quadratic_equation_application.h"

int main(int argc, const char** argv) {
    QuadraticEquationApplication app;
    std::string output = app(argc, argv);
    std::cout << output.c_str() << std::endl;
    return 0;
}
