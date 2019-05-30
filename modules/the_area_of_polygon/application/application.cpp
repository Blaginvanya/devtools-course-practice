// Copyright 2019 Dudchenko Anton

#include <iostream>
#include <string>

#include "include/the_area_of_polygon_app.h"

int main(int argc, const char** argv) {
    AreaCalculator app;
    std::cout << app(argc, argv);
    return 0;
}
