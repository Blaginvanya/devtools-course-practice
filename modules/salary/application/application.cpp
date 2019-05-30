// Copyright 2019 Ryabova Alyona

#include <iostream>

#include "include/salary_application.h"

int main(int argc, const char** argv) {
    SalaryApplication app;
    std::cout << app(argc, argv);
    return 0;
}
