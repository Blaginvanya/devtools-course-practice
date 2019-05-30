// Copyright 2019 Ivan Yunin

#include <iostream>

#include "include/temperature_calculator.h"

int main(int argc, const char** argv) {
    TemperatureCalculator app;
    std::cout << app(argc, argv);
    return 0;
}
