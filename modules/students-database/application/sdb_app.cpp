// Copyright 2019 Kudrin Matvey

#include <stdlib.h>
#include <iostream>
#include <string>

#include "include/sdb_app.h"

int main(int argc, const char** argv) {
    SdbApp app;
    std::cout << app(argc, argv) << std::endl;

    return 0;
}
