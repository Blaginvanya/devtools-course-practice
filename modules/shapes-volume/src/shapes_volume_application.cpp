// Copyright 2019 Kurakin Mikhaiul

#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include "include/shapes_volume_application.h"

std::string ShapesVolumeApplication::operator()(int argc, const char **argv) {
    std::string output = "volume = ";
    if (argc == 1) {
        return Help();
    }
    try {
        output += ParseCommand(argc, argv);
    }
    catch (std::runtime_error &exp) {
        return exp.what();
    }
    catch(std::string &exp) {
        return exp;
    }
    return output;
}

double ShapesVolumeApplication::ParseDouble(const char *arg) {
    char *end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string ShapesVolumeApplication::Help() {
    return "ShapesVolume class application:\n"
           "Commands:\n"
           "help - print help information\n"
           "calc <parameter> calculate volume of shape, "
           "shapes you can shoose using parameters\n"
           "Parameters listed below:\n"
           "cone - choose cone\n"
           "sphere - choose sphere\n"
           "cylinder - choose cylinder\n"
           "paral - choose parallelipiped\n"
           "cube - choose cube\n"
           "tetr - choose tetrahedron\n"
           "arguments for shapes:\n"
           "cone - <radius> <height>\n"
           "sphere - <radius>\n"
           "cylinder - <radius> <height>\n"
           "paral - <edgeLength> <edgeHeight> <edgeWidth>\n"
           "cube - <edgelength\n>"
           "tetr - <edgeLength\n>";
}

std::string ShapesVolumeApplication::ParseCommand(int argc, const char **arg) {
    if (strcmp(arg[1], "help") == 0) {
        return Help();
    } else if (strcmp(arg[1], "calc") == 0) {
        return ParseParams(argc, arg);
    } else {
        throw std::runtime_error("wrong command");
    }
}

std::string ShapesVolumeApplication::ParseParams(int argc, const char **argv) {
    if (strcmp(argv[2], "cone") == 0) {
        if (argc < 5)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(ShapesVolume::ConeVolume(arg1, arg2));
    } else if (strcmp(argv[2], "sphere") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(ShapesVolume::SphereVolume(arg1));
    } else if (strcmp(argv[2], "cylinder") == 0) {
        if (argc < 5)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(ShapesVolume::CylinderVolume(arg1, arg2));
    } else if (strcmp(argv[2], "paral") == 0) {
        if (argc < 6)
            throw std::runtime_error("too few arguments");
        double a1 = ParseDouble(argv[3]);
        double a2 = ParseDouble(argv[4]);
        double a3 = ParseDouble(argv[5]);
        return std::to_string(ShapesVolume::ParallelepipedVolume(a1, a2, a3));
    } else if (strcmp(argv[2], "cube") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(ShapesVolume::CubeVolume(arg1));
    } else if (strcmp(argv[2], "tetr") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(ShapesVolume::TetrahedronVolume(arg1));
    } else {
        throw std::runtime_error("wrong param");
    }
}
