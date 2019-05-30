// Copyright 2019 Astafeva Irina

#include <iostream>

#include "include/calculate_price_application.h"

int main(int argc, const char ** argv) {
    CalculatePriceApplication app;
    std::cout << app(argc, argv);
    return 0;
}
