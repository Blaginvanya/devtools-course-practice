// Copyright 2019 Repin Vladimir

#include <string>

#include "include/lcd_digits.h"
#include "include/lcd_digits_application.h"

void LCDDigitsApplication::Help(const char* appname) {
    message_ = message_ +
        "This application prints multiple strings in LCD format.\n\n"
        "Please provide arguments in the following format:\n\n"
        "  $ " + appname + " <str_1> <str_2> ... <str_n>\n"
        "Where str_i is string consisiting of digits, '.', ':'.\n";
}

std::string LCDDigitsApplication::operator()(int argc, const char** argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            try {
                message_ += LCDDigits::LCD(argv[i]) + '\n';
            }
            catch(const std::string& str) {
                message_ = "";
                Help(argv[0]);
                message_ = str + message_;
                break;
            }
        }
    } else {
        Help(argv[0]);
    }
    return message_;
}
