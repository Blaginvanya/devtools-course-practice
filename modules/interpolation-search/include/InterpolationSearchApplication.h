// Copyright 2019 Vikhrev Ivan

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATIONSEARCHAPPLICATION_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATIONSEARCHAPPLICATION_H_

#include <string>
#include "include/InterpolationSearch.h"

class InterpolationSearchApplication {
 private:
    const std::string info_ =
    "This is a demo app for demonstrating interpolation search.\n"
    "Application works only with sorted arrays of integers.\n"
    "You should specify next agruments:\n"
    "<path to file with array> <number of integers> <integer to find>\n"
    "Application returns index of required number.\n";
    std::string file_name_;
    int* numbers_;
    int n_;
    int n_to_find_;
    bool read_file();
    InterpolationSearch isearch_;

 public:
    InterpolationSearchApplication() = default;
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATIONSEARCHAPPLICATION_H_
