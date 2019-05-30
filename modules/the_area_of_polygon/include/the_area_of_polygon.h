// Copyright 2019 Kondrina Tatyana

#include <vector>

#ifndef MODULES_THE_AREA_OF_POLYGON_INCLUDE_THE_AREA_OF_POLYGON_H_
#define MODULES_THE_AREA_OF_POLYGON_INCLUDE_THE_AREA_OF_POLYGON_H_

class AreaOfPolygon {
 private:
    std::vector<std::vector<int>> points_;
 public:
    explicit AreaOfPolygon(std::vector<std::vector<int>> p = { {} });
    ~AreaOfPolygon();
    double Area();
    void SetPoint(int n, std::vector<int> p);
};
#endif  // MODULES_THE_AREA_OF_POLYGON_INCLUDE_THE_AREA_OF_POLYGON_H_
