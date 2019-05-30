// Copyright 2019 Sadikov Artem

#include <string>

#include "include/range_operation.h"
#include "include/range.h"

int main(int argc, const char** argv) {
    RangeOperation app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
