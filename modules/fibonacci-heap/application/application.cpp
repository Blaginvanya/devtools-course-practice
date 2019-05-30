// Copyright 2019 Karasev Anton

#include <include/fibonacci_heap_application.h>

#include <iostream>

int main(int argc, char const *argv[]) {
    FibonacciHeapApplication application;
    std::cout << application(argc, argv);
    return 0;
}
