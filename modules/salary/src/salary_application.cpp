// Copyright 2019 Ryabova Alyona

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>

#include "include/TSalary.h"
#include "include/salary_application.h"

SalaryApplication::SalaryApplication() : message_("") {}

void SalaryApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a application for class salary.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <salary> <norm> " +
          "<overtime> <vacantion> <worked_hours>\n\n" +

          "Where all arguments are integer numbers.\n";
}

bool SalaryApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInteger(const char* arg) {
    char* end;
    int64_t value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    if (value <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
        value >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
        throw std::string("Number is out of bounds!");
    }

    return value;
}

std::string SalaryApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.salary = parseInteger(argv[1]);
        args.norm = parseInteger(argv[2]);
        args.overtime = parseInteger(argv[3]);
        args.vacantion = parseInteger(argv[4]);
        args.worked_hours = parseInteger(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;

    try {
        TSalary sal(args.salary, args.norm, args.worked_hours,
        args.overtime, args.vacantion);

        double salary = sal.Payroll();
        stream << "Salary = " << salary;
    }
        catch(std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}

