// Copyright 2019 Kondrina Tatyana

#include <vector>
#include <iostream>
#include "include/the_area_of_polygon.h"

AreaOfPolygon::AreaOfPolygon(std::vector<std::vector<int>> p):points_(p) {}

AreaOfPolygon::~AreaOfPolygon() {
    unsigned int i;
    for (i = 0; i < points_.size(); i++)
        points_[i].clear();
    points_.clear();
}

double AreaOfPolygon::Area() {
    double sum = 0;
    unsigned int i;
    for (i = 0; i < points_.size() - 1; i++) {
        sum += abs(points_[i][0] * points_[i + 1][1] -
            points_[i + 1][0] * points_[i][1]);
    }
    sum += abs(points_[i][0] * points_[0][1] -
        points_[0][0] * points_[i][1]);
    return sum * 0.5;
}

void AreaOfPolygon::SetPoint(int n, std::vector<int> p) {
    if (n < 0) throw - 1;
    points_[n] = p;
}
