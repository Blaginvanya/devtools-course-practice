// Copyright 2019 Yakovlev Pavel

#include <cstdlib>
#include <iostream>
#include <string>

#include "include/demand_app.h"

int main(int argc, char const *argv[]) {
    DemandApp application;
    std::cout << application(argc, argv);
    return 0;
}
