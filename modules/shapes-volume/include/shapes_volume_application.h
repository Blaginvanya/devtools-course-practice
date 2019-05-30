// Copyright 2019 Kurakin Mikhail

#ifndef MODULES_SHAPES_VOLUME_INCLUDE_SHAPES_VOLUME_APPLICATION_H_
#define MODULES_SHAPES_VOLUME_INCLUDE_SHAPES_VOLUME_APPLICATION_H_
#include <string>
#include "include/shapes_volume.h"

class ShapesVolumeApplication {
 private:
    std::string ParseCommand(int argc, const char** argv);
    std::string ParseParams(int argc, const char** arg);
    double ParseDouble(const char* arg);
 public:
    std::string Help();
    ShapesVolumeApplication() = default;
    std::string operator()(int argc, const char **argv);
};

#endif  // MODULES_SHAPES_VOLUME_INCLUDE_SHAPES_VOLUME_APPLICATION_H_
