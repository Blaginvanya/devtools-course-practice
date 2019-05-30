// Copyright 2019 Malkin Danil

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOMS_CALCULATOR_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOMS_CALCULATOR_H_

#include <string>
#include <vector>

#include "include/monom.h"

class PolynomsCalculator {
 public:
    PolynomsCalculator() = default;
    std::string operator()(int argc, const char** argv);
    std::string Calculate(const std::string& arg1, const std::string& arg2,
        const std::string& op);
 private:
    std::string Info();
    // Wait support std::regex and new configuration for environment of Linux
    // bool checkCorrectPolynoms(const std::string& str);
    bool CheckOperation(const std::string& str);
    std::string Preprocessing(const std::string& str);
    Monom CreateMonom(const std::string& str);
    std::vector<Monom> ParsePolynom(const std::string& str);
    typedef struct {
        std::string operation;
        std::string arg1;
        std::string arg2;
    } Arguments;
};

#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOMS_CALCULATOR_H_
