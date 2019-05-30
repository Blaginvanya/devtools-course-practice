// Copyright 2019 Gribanov Mihail

#include "include/quadratic_equation_application.h"
#include "include/quadratic_equation.h"

#include <stdint.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

std::string QuadraticEquationApplication::operator()
(int argc, const char** argv) {
    QuadraticEquationApplication app;
    std::ostringstream stream;

    if (!CheckArguments(argc, argv)) {
        return message_;
    }

    for (int i = 1; i < 4; i++)
        coef[i-1] = atoi(argv[i]);

    try {
        QuadraticEquation qe(coef[0], coef[1], coef[2]);

        if (qe.GetX1() == qe.GetX2())
            stream << "X1 = X2 = " << qe.GetX1();
        else
            stream << "X1 = " << qe.GetX1() << ", X2 = " << qe.GetX2();

        message_ = stream.str();
        return message_;
    }
    catch (const char* s) {
        stream << s;
        message_ = stream.str();
        return message_;
    }
}

void QuadraticEquationApplication::Help
(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a quadratic equation calculator application. \n\n" +
        "Please, provide arguments in the following format: \n\n "
        "  $ " + appname + " <coef_a> <coef_b> <coef_c> \n\n";
}

bool QuadraticEquationApplication::CheckArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}
