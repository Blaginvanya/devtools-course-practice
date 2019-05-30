// Copyright 2019 Dudchenko Anton

#include <string>
#include <cstring>
#include <vector>
#include "include/the_area_of_polygon_app.h"

void AreaCalculator::Info(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a area calculator application. \n\n" +
        "Please, provide arguments in the following format: \n\n"
        " $ " + appname + " <x1 y1> <x2 y2> ... <xn yn>, \n\n" +
        "Where all arguments are integer numbers. ";
}


bool AreaCalculator::CheckArguments(int argc, const char** argv) {
    if (argc == 1) {
        Info(argv[0]);
        return false;
    }
    if (argc % 2 == 0) {
        Info(argv[0], "ERROR : Should be pass the points "
                      "in the format <x y>. \n\n");
        return false;
    }
    for (int i = 1; i < argc; i++) {
        if ((atoi(argv[i]) == 0) && (strcmp(argv[i], "0") != 0)) {
            Info(argv[0], "ERROR : All arguments must be integers. \n\n");
            return false;
        }
    }
    return true;
}

std::string AreaCalculator::operator()(int argc, const char** argv) {
    std::vector<std::vector<int>> argument;
    std::vector<int> tmp;

    if (!CheckArguments(argc, argv)) {
        return message_;
    }
    for (int i = 1; i < argc; i+=2) {
        tmp.push_back(std::atoi(argv[i]));
        tmp.push_back(std::atoi(argv[i + 1]));
        argument.push_back(tmp);
        tmp.clear();
    }

    AreaOfPolygon p(argument);
    message_ = "Area of polygon = " + std::to_string(p.Area());
    message_ = message_.substr(0, message_.size() - 4);
    return message_;
}
