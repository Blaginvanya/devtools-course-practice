// Copyright 2019 Likholat Ann

#include "include/string_calculator.h"
#include "include/string_calculator_app.h"

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

StringCalculatorApp::StringCalculatorApp() : message_(""), expression_("") {}

void StringCalculatorApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a string calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <string with expression for calculating> " +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*', '/', '^'.\n" +
        "You also can use '(' and ')'.\n\n";;
}

bool StringCalculatorApp::validateNumberOfArguments
                          (int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 2) {
        help(argv[0], "ERROR: Should be 1 argument.\n\n");
        return false;
    }
    return true;
}

std::string StringCalculatorApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    expression_ = argv[1];

    StringCalculator sc;

    sc.set_infix(expression_);

    double res;
    std::ostringstream stream;

    try {
        res = sc.Calculate();
    }
    catch (std::string& str) {
        return str;
    }

    stream << "Result = " << res << "\n";

    message_ = stream.str();

    return message_;
}
