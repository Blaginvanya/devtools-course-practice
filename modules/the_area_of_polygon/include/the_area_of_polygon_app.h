// Copyright 2019 Dudchenko Anton

#ifndef MODULES_THE_AREA_OF_POLYGON_INCLUDE_THE_AREA_OF_POLYGON_APP_H_
#define MODULES_THE_AREA_OF_POLYGON_INCLUDE_THE_AREA_OF_POLYGON_APP_H_

#include <string>
#include "include/the_area_of_polygon.h"

class AreaCalculator {
 private:
    std::string message_;
    void Info(const char* appname, const char* message = "");
    bool CheckArguments(int argc, const char** argv);

 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_THE_AREA_OF_POLYGON_INCLUDE_THE_AREA_OF_POLYGON_APP_H_
