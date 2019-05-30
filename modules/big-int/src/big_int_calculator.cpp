// Copyright 2019 Volkov Pavel

#include "include/big_int.h"
#include "include/big_int_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>


BigIntCalculator::BigIntCalculator() : message_("") {}

void BigIntCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a big int number calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <big_int> <big_int> " +
          "<operation>\n\n" +

          "Where all arguments are very long integer numbers, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool BigIntCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

std::string parseCorrectInt(const char* arg) {
    std::string value;

    unsigned int iterator = 0;

    value = arg;

    if (value == "-" || value.length() == 0) {
        throw std::string("Wrong number format, zero length!");
    }

    if (value[0] == '-') {
        iterator++;
    }

    while (iterator < value.length()) {
        if (value[iterator] > '9' || value[iterator] < '0') {
            throw std::string("Wrong number format!");
        }
        iterator++;
    }

    return value;
}

char parseOperation(const char* arg) {
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

std::string BigIntCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.operand_1 = parseCorrectInt(argv[1]);
        args.operand_2 = parseCorrectInt(argv[2]);
        args.operation = parseOperation(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    BigInt op_1(args.operand_1);
    BigInt op_2(args.operand_2);
    BigInt result;

    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        result = op_1 + op_2;
        stream << "Result = " << result.BigIntToString();
        break;
     case '-':
        result = op_1 - op_2;
        stream << "Result = " << result.BigIntToString();
        break;
     case '*':
        result = op_1 * op_2;
        stream << "Result = " << result.BigIntToString();
        break;
     case '/':
        try {
            result = op_1 / op_2;
            stream << "Result = " << result.BigIntToString();
            break;
        }
        catch(std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;


    return 0;
}
