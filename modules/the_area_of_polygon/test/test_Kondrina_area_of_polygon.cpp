// Copyright 2019 Kondrina Tatyana

#include <vector>
#include "include/the_area_of_polygon.h"
#include "gtest/gtest.h"

TEST(Test_Area_Of_Polygon, Can_Calculate_Area) {
    // Arrange
    AreaOfPolygon p({ {-1, 0}, {-1, 1}, {0, 1}, {0, 0} });

    // Act
    double s = p.Area();

    // Assert
    EXPECT_EQ(1, s);
}

TEST(Test_Area_Of_Polygon, Can_Set_Point) {
    // Arrange
    AreaOfPolygon p({ {0, 0}, {-1, 1}, {0, 1}, {0, 0} });

    // Act
    p.SetPoint(0, { -1, 0 });
    double s = p.Area();

    // Assert
    EXPECT_EQ(1, s);
}

TEST(Test_Area_Of_Polygon, Cannot_Set_Point_With_Negativ_Number) {
    // Arrange
    AreaOfPolygon p({ { 0, 0}, { -1, 1}, { 0, 1}, { 0, 0} });

    // Assert
    ASSERT_ANY_THROW(p.SetPoint(-1, { -1, 0 }));
}
