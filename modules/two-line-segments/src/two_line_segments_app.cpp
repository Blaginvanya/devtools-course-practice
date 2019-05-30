// Copyright 2019 Fedotov Vlad

#include "include/two_line_segments.h"
#include "include/two_line_segments_app.h"

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <sstream>
#include <string>

void TwoLineSegmentsApp::Help(const char* appname,
                              const char* message) {
    message_ =
    std::string(message) +
    "This application determines whether.\n\n" +
    "two line segments intersect or not.\n" +
    "Please provide arguments in the following format:\n" +
    "$" + std::string(appname) + " <x0> <y0> <x1> <y1> <x2> <y2> <x3> <y3>\n" +
    "where x0, y0, x1, y1 are the coordinates of the first line segment,\n" +
    "x2, y2, x3, y3 - of the second.\n";
}

bool TwoLineSegmentsApp::ValidateNumberOfArguments(int argc,
                                                   const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 9) {
        Help(argv[0], "ERROR: Should be 8 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string TwoLineSegmentsApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x0 = parseDouble(argv[1]);
        args.y0 = parseDouble(argv[2]);
        args.x1 = parseDouble(argv[3]);
        args.y1 = parseDouble(argv[4]);
        args.x2 = parseDouble(argv[5]);
        args.y2 = parseDouble(argv[6]);
        args.x3 = parseDouble(argv[7]);
        args.y3 = parseDouble(argv[8]);
    }
    catch (std::string& str) {
        return str;
    }

    Point p0;
    Point p1;
    Point p2;
    Point p3;
    TwoLineSegments tls;

    p0.SetCoordinatesToPoint(args.x0, args.y0);
    p1.SetCoordinatesToPoint(args.x1, args.y1);
    p2.SetCoordinatesToPoint(args.x2, args.y2);
    p3.SetCoordinatesToPoint(args.x3, args.y3);

    tls.SetCoordinatesToFirstLine(p0, p1);
    tls.SetCoordinatesToSecondLine(p2, p3);

    std::ostringstream stream;

    if (tls.AreIntersect())
        stream << "These two line segments intersect!\n";
    else
        stream << "These two line segments DON'T intersect.";
    message_ = stream.str();

    return message_;
}
