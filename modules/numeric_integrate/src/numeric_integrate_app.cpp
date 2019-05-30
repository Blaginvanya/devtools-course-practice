// Copyright 2019 Vdovin Eugene

#include "include/numeric_integrate.h"
#include "include/numeric_integrate_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

NumericIntegrateApp::NumericIntegrateApp() : message_("") {}

void NumericIntegrateApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a numeric integrate application.\n\n" +
          "The application numeric integrate function:\n" +
          "if x < 0 then f(x) = -sqrt(-x)\n" +
          "if x >= 0 then f(x) = sqrt(x)\n" +
          "in two ways: rectangle and trapezium.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <a> <b> " +
          "<n> <method>\n\n" +

          "a and b - the border of integration,\n" +
          "n - number of partitions.\n" +
          "method - method numeric integrate, where\n" +
          "rectangle - Rectangle numeric integrate\n" +
          "trapezium - Trapezium numeric integrate\n\n" +

          "Where all arguments are double-precision numbers and integers\n";
}

bool NumericIntegrateApp::ValidateNumberOfArguments(int argc,
                                                    const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 5) {
        Help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int ParseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int ParseMethod(const char* arg) {
    int m;
    if (strcmp(arg, "rectangle") == 0) {
        m = 1;
    } else if (strcmp(arg, "trapezium") == 0) {
        m = 2;
    } else {
        throw std::string("Wrong method format!");
    }
    return m;
}

std::string NumericIntegrateApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a      = ParseDouble(argv[1]);
        args.b      = ParseDouble(argv[2]);
        args.n      = ParseInt(argv[3]);
        args.method = ParseMethod(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    NumericIntegrate c;

    c.SetSection(args.a, args.b);

    double res;
    std::ostringstream stream;
    switch (args.method) {
     case 1:
        res = c.RectangleMethod(args.n);
        stream << "Result = " << res;
        break;
     case 2:
        res = c.TrapeziumMethod(args.n);
        stream << "Result = " << res;
        break;
    }

    message_ = stream.str();

    return message_;
}
