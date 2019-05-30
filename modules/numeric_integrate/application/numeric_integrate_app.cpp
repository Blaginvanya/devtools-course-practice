// Copyright 2019 Vdovin Eugene

#include <stdlib.h>
#include <iostream>
#include <string>

#include "include/numeric_integrate_app.h"

int main(int argc, const char** argv) {
    NumericIntegrateApp app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
