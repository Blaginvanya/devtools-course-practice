// Copyright 2019 Sitkin Dmitry

#include <string>
#include <iostream>
#include "include/mortgage_calculator.h"
#include "include/calculator.h"

std::string Calculator::Help(const char* appname, const char* message) {
    return std::string(message) +
        "This app allows you to calculate" +
        "the amount of your monthly fee and " +
        "overpayment for the apartment. \n " +
        "Please, provide arguments in the following " +
        "format: \n $ " + appname + " appartment price, " +
        "first payment, term (month), interest";
}

bool Calculator::ValidateArgs(int argc, const char** argv) {
    bool isNoArgsProvided = argc == 1;
    if (isNoArgsProvided) {
        std::cout << Help(argv[0]);
        return false;
    }
    bool isEnoughArgs = argc == 5;
    if (!isEnoughArgs) {
        std::cout << Help(argv[0], "Please, provide exactly 4 arguments. \n");
        return false;
    }
    char* end;
    for (int i = 1; i < argc; i++) {
        if (strtod(argv[i], &end) < 0) {
            std::cout << Help(argv[0], "Wrong argument! \n");
            return false;
        } else if (end[0]) {
            std::cout << Help(argv[0], "Wrong number format! \n");
            return false;
        }
    }
    return true;
}

std::string Calculator::operator()(int argc, const char** argv) {
    if (!ValidateArgs(argc, argv))
        return "";
    MortgageCalculator calc;
    std::string monthly_payment_ =
        std::to_string(static_cast<int>(calc.CalculatePayments(
            std::stoi(argv[1]),
            std::stoi(argv[2]),
            std::stoi(argv[3]),
            std::stoi(argv[4]))));
    return monthly_payment_;
}
