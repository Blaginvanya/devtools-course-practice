// Copyright 2019 Fedotov Vlad

#ifndef MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_APP_H_
#define MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_APP_H_

#include "include/two_line_segments.h"
#include <string>

class TwoLineSegmentsApp {
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double x0;
        double y0;
        double x1;
        double y1;
        double x2;
        double y2;
        double x3;
        double y3;
    } Arguments;
 public:
    TwoLineSegmentsApp() = default;
    std::string operator()(int argc, const char ** argv);
};

#endif  // MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_APP_H_
