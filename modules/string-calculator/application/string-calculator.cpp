// Copyright 2019 Likholat Ann

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/string_calculator_app.h"

int main(int argc, const char** argv) {
    StringCalculatorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
