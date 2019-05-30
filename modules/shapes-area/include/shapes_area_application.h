// Copyright 2019 Evdokimov Artem

#ifndef MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_APPLICATION_H_
#define MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_APPLICATION_H_

#include <string>
#include "include/shapes_area.h"

class ShapesAreaApplication {
 private:
    std::string ParseCommand(int argc, const char** argv);
    std::string ParseParams(int argc, const char** arg);
    double ParseDouble(const char* arg);
 public:
    std::string Help();
    ShapesAreaApplication() = default;
    std::string operator()(int argc, const char **argv);
};

#endif  // MODULES_SHAPES_AREA_INCLUDE_SHAPES_AREA_APPLICATION_H_
