// Copyright 2019 Repin Vladimir

#include <iostream>
#include "include/lcd_digits_application.h"

int main(int argc, char const ** argv) {
    LCDDigitsApplication app;
    std::cout << app(argc, argv);
    return 0;
}
