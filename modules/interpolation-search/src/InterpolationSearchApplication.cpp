// Copyright 2019 Vikhrev Ivan

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "include/InterpolationSearchApplication.h"


bool InterpolationSearchApplication::read_file() {
    bool res = false;
    std::ifstream file(file_name_);
    if (file.is_open()) {
        for (int i = 0; i < n_; i++) {
            file >> numbers_[i];
        }
        res = true;
    }
    file.close();
    return res;
}

std::string InterpolationSearchApplication::operator()
                         (int argc, const char** argv) {
    std::string message = info_;
    if (argc > 3) {
        file_name_ = argv[1];
        n_ = atoi(argv[2]);
        n_to_find_ = atoi(argv[3]);
        numbers_ = new int[n_];
        if (read_file()) {
            isearch_.SetSortedData(numbers_, n_);
            int i = isearch_.Search(n_to_find_);
            if (i != -1) {
                message = "Index of required number is " +
                                     std::to_string(i) + '\n';
            } else {
                message = "Required number isn't found\n";
            }
        } else {
            message = "Can't open file\n";
        }
        delete[] numbers_;
    }
    return message;
}
