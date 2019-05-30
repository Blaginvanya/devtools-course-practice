// Copyright 2019 Evdokimov Artem

#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include "include/shapes_area_application.h"

std::string ShapesAreaApplication::operator()(int argc, const char **argv) {
    std::string output = "area = ";
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

double ShapesAreaApplication::ParseDouble(const char *arg) {
    char *end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string ShapesAreaApplication::Help() {
    return "ShapesArea class application:\n"
           "Commands:\n"
           "help - print help information\n"
           "calc <parameter> calculate area of shape, "
           "shapes you can shoose using parameters\n"
           "Parameters listed below:\n"
           "cone - choose cone\n"
           "sphere - choose sphere\n"
           "cylinder - choose cylinder\n"
           "paral - choose parallelipiped\n"
           "cube - choose cube\n"
           "tetr - choose tetrahedron\n"
           "arguments for shapes:\n"
           "cone - <radius> <generator>\n"
           "sphere - <radius>\n"
           "cylinder - <radius> <height>\n"
           "paral - <edgeLength> <edgeHeight> <edgeWidth>\n"
           "cube - <edgelength\n>"
           "tetr - <edgeLength\n>";
}

std::string ShapesAreaApplication::ParseCommand(int argc, const char **arg) {
    if (strcmp(arg[1], "help") == 0) {
        return Help();
    } else if (strcmp(arg[1], "calc") == 0) {
        return ParseParams(argc, arg);
    } else {
        throw std::runtime_error("wrong command");
    }
}

std::string ShapesAreaApplication::ParseParams(int argc, const char **argv) {
    if (strcmp(argv[2], "cone") == 0) {
        if (argc < 5)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(ShapesArea::ConeArea(arg1, arg2));
    } else if (strcmp(argv[2], "sphere") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(ShapesArea::SphereArea(arg1));
    } else if (strcmp(argv[2], "cylinder") == 0) {
        if (argc < 5)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(ShapesArea::CylinderArea(arg1, arg2));
    } else if (strcmp(argv[2], "paral") == 0) {
        if (argc < 6)
            throw std::runtime_error("too few arguments");
        double a1 = ParseDouble(argv[3]);
        double a2 = ParseDouble(argv[4]);
        double a3 = ParseDouble(argv[5]);
        return std::to_string(ShapesArea::ParallelepipedArea(a1, a2, a3));
    } else if (strcmp(argv[2], "cube") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(ShapesArea::CubeArea(arg1));
    } else if (strcmp(argv[2], "tetr") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(ShapesArea::TetrahedronArea(arg1));
    } else {
        throw std::runtime_error("wrong param");
    }
}
