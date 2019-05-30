// Copyright 2019 Bykovskaya Alina

#include <iostream>
#include "include/priority-queue-application.h"

int main(int argc, const char**argv) {
    PriorityApp prior;
    std::cout << "Hello!" << std::endl;
    std::cout << prior(argc, argv);
    return 0;
}
