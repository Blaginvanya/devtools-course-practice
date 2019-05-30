// Copyright 2019 Tolstikov Maksim

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/dHeap_application.h"

int main(int argc, const char** argv) {
    DHeapApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
