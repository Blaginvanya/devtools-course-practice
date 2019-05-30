// Copyright 2019 Kurakin Mikhail

#include <iostream>
#include "include/shapes_volume_application.h"

int main(int argc, char const** argv) {
    ShapesVolumeApplication application;
    std::cout << application(argc, argv);
    return 0;
}
