// Copyright 2019 Gaydaychuk Yury

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/prime_counter.h"

int main(int argc, const char** argv) {
    PrimeCounter app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
