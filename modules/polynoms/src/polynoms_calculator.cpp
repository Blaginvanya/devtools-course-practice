// Copyright 2019 Malkin Danil

#include "include/polynoms_calculator.h"

// #include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "include/polynom.h"

std::string PolynomsCalculator::Info() {
    std::string res = "This is a polynom application\n";
    res += "Please,enter the expression in the following format:";
    res +="$ <appname> <first polynom> <second polynom> <operation>\n";
    res += "Available operations: +, -, *.\n";
    return res;
}

Monom PolynomsCalculator::CreateMonom(const std::string& str) {
    double coeff = 1;
    std::map<char, double> vars;
    std::size_t res = 0;
    std::size_t curr = res;
    std::string str1 = str.substr(0, str.length());

    while ((isdigit(str1[curr]) || str1[curr] == '-' ||
        str1[curr] == '+' || str1[curr] == '.') && (curr < str1.length())) {
        curr++;
    }
    if (curr > 0) {
        coeff = std::stod(str1.substr(res, curr));
    }
    str1.erase(res, curr);
    res = str1.find('^');;
    curr = res;
    while (res != std::string::npos) {
        curr++;
        if (isdigit(str1[curr]) || str1[curr] == '-' || str1[curr] == '+') {
            while (isdigit(str1[curr])) {
                curr++;
            }
            vars.insert({ str1[res - 1],
                std::stod(str1.substr(res + 1, curr - (res + 1))) });
            str1.erase(res, curr - res);
            res = str1.find('^');
            curr = res;
        } else {
            if (curr == res + 1) {
                throw std::invalid_argument("Error");
            }
        }
    }
    return Monom(coeff, vars);
}

// It wait new version gcc for TREVIS
/*
bool PolynomsCalculator::checkCorrectPolynoms(const std::string& str) {
    const std::regex reg_str("([+,-]?(([0-9]+.[0-9]+)?([a-z]\\^-?[0-9]+|[a-z])+|([0-9]+.[0-9]+)?))+");
    return std::regex_match(str, reg_str);
};
*/
bool PolynomsCalculator::CheckOperation(const std::string& str) {
    if (str == "+" || str == "-" || str == "*") {
        return true;
    }
    return false;
}

std::vector<Monom> PolynomsCalculator::ParsePolynom(const std::string& str) {
    std::vector<Monom> resm;
    std::string str1 = str.substr(0, str.length());
    std::size_t res = 0;
    std::size_t curr = res;

    while (curr != str1.length()) {
        if ((str1[curr] == '-' || str1[curr] == '+') &&
            (isalpha(str1[curr - 1]) || isdigit(str1[curr - 1]))) {
            resm.push_back(CreateMonom(str1.substr(res, curr - res)));
            res = curr;
        }
        curr++;
    }
    resm.push_back(CreateMonom(str1.substr(res, str1.length() - res)));
    return resm;
}

std::string PolynomsCalculator::Preprocessing(const std::string& str) {
    std::string str1 = str.substr(0, str.length());

    for (std::size_t i = 0; i < (str1.length() - 1); i++) {
        if (!(isalpha(str1[i]) || isdigit(str1[i]) || str1[i] == '^' ||
            str1[i] == '.' || str1[i] == '+' || str1[i] == '-')) {
            throw std::invalid_argument("Error");
        } else {
            if (str1[i] == '^') {
                if (i == 0) {
                    throw std::invalid_argument("Error");
                } else {
                    if (!isalpha(str1[i - 1])) {
                        throw std::invalid_argument("Error");
                    }
                }
            }
            if (str1[i] == '.') {
                if (i == 0) {
                    throw std::invalid_argument("Error");
                } else {
                    if (!(isdigit(str1[i - 1]) && isdigit(str1[i + 1]))) {
                        throw std::invalid_argument("Error");
                    }
                }
            }
        }
        if (isalpha(str1[i]) && (isalpha(str1[i + 1]) ||
            str1[i + 1] == '+' || str1[i + 1] == '-')) {
            str1.insert(i+1, "^1");
        }
    }
    if (isalpha(str1[str1.length() - 1])) {
        str1+="^1";
    }
    return str1;
}

std::string PolynomsCalculator::Calculate(const std::string& arg1,
    const std::string& arg2, const std::string& operation) {
    try {
            Polynom pol1(ParsePolynom(Preprocessing(arg1)));
            Polynom pol2(ParsePolynom(Preprocessing(arg2)));
            std::string op = operation;

            if (op == "+") {
                return (pol1 + pol2).ToString();
            }
            if (op == "-") {
                return (pol1 - pol2).ToString();
            }
            if (op == "*") {
                return (pol1 * pol2).ToString();
            }
            return "Error";
    }
    catch (const std::invalid_argument& e) {
        return "Error";
    }
}

std::string PolynomsCalculator::operator()(int argc, const char** argv) {
    Arguments arg;
    Polynom pol1;
    Polynom pol2;
    if (argc == 2) {
        if (std::string(argv[1]) == "help") {
            return Info();
        }
    }
    if (argc != 4) {
        return "Invalid count argument.";
    }
    arg.arg1 = argv[1];
    arg.arg2 = argv[2];
    arg.operation = argv[3];
    // std::regex
    /*
    checkCorrectPolynoms(arg.arg1) && checkCorrectPolynoms(arg.arg2) &&
    */
    if (CheckOperation(arg.operation)) {
        return Calculate(arg.arg1, arg.arg2, arg.operation);
    } else {
        return "Incorrect input.";
    }
}
