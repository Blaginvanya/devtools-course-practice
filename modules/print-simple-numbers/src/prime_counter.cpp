// Copyright 2019 Gaydaychuk Yuri

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/print-simple-numbers.h"
#include "include/prime_counter.h"

PrimeCounter::PrimeCounter() : message_("") {}

void PrimeCounter::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a simple printer of prime numbers.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <left_boundary> " +
          "<right_boundary>\n\n" +

          "Where all arguments are integer numbers, \n"

          "but it rather robust to parse double parameter\n";
}

bool PrimeCounter::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string PrimeCounter::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.left_boundary = parseInt(argv[1]);
        args.right_boundary = parseInt(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    SimpleNumbers check_eng;

    int res = check_eng.SizeOfArray(args.left_boundary, args.right_boundary);

    std::ostringstream stream;

    if (res == -1) {
        stream << "No prime numbers in selected interval.";
    } else {
        stream << "Count of prime numbers between "
           << args.left_boundary << " and  "
           << args.right_boundary << " equal " << res;
    }

    message_ = stream.str();

    return message_;
}
