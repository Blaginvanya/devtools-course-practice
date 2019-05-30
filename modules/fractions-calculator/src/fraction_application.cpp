// Copyright 2019 Andronov Maxim

#include "include/fraction.h"
#include "include/fraction_application.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

void FractionCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a fraction calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <f1_num> <f1_den> " +
        "<f2_num> <f2_den> <operation>\n\n" +
        "Where all arguments are integer numbers, " +
        "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool FractionCalculator::ValidateNumberOfArguments(int argc,
                                   const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 6) {
        Help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

int ParseInteger(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 0);

    if (end == arg)
        throw std::string(arg) + " is not the number";

    return value;
}

char ParseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string FractionCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.f1_num = ParseInteger(argv[1]);
        args.f1_den = ParseInteger(argv[2]);
        args.f2_num = ParseInteger(argv[3]);
        args.f2_den = ParseInteger(argv[4]);
        args.operation = ParseOperation(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }

    Fraction f1;
    Fraction f2;

    f1.SetNum(args.f1_num);
    f1.SetDen(args.f1_den);
    f2.SetNum(args.f2_num);
    f2.SetDen(args.f2_den);

    Fraction f;
    std::ostringstream stream;
    switch (args.operation) {
    case '+':
        f = f1 + f2;
        stream << "Numerator = " << f.GetNum() << " "
            << "Denominator = " << f.GetDen();
        break;
    case '-':
        f = f1 - f2;
        stream << "Numerator = " << f.GetNum() << " "
            << "Denominator = " << f.GetDen();
        break;
    case '*':
        f = f1 * f2;
        stream << "Numerator = " << f.GetNum() << " "
            << "Denominator = " << f.GetDen();
        break;
    case '/':
            f = f1 / f2;
            stream << "Numerator = " << f.GetNum() << " "
                << "Denominator = " << f.GetDen();
            break;
    }

    message_ = stream.str();

    return message_;
}
