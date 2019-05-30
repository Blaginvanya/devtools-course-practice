// Copyright 2019 Evdokimov Artem

#include <iostream>
#include "include/shapes_area_application.h"

int main(int argc, char const** argv) {
    ShapesAreaApplication application;
    std::cout << application(argc, argv);
    return 0;
}
