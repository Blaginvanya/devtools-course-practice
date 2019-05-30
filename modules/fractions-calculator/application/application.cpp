// Copyright 2019 Andronov Maxim

#include <iostream>

#include "include/fraction_application.h"

int main(int argc, const char** argv) {
    FractionCalculator app;
    std::cout << app(argc, argv);
    return 0;
}
