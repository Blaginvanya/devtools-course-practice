// Copyright 2019 Guseva Catherine

#include <gtest/gtest.h>

#include "include/range.h"

TEST(Guseva_Catherine_RangeTest, Can_Create_Interval) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(Range r("[23,45]"));
}

TEST(Guseva_Catherine_RangeTest, Can_Get_End_Points) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    ASSERT_NO_THROW(r.EndPoints());
}

TEST(Guseva_Catherine_RangeTest, Can_Get_All_Points) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    ASSERT_NO_THROW(r.GetAllPoints());
}

TEST(Guseva_Catherine_RangeTest, Contain_Integer_Interval) {
    // Arrange
    Range r("[23,45)");
    int ar[4] = { 23, 32, 26, 38 };

    // Act & Assert
    EXPECT_TRUE(r.IntegerRangeContains(ar, 4));
}

TEST(Guseva_Catherine_RangeTest, No_Contain_Integer_Interval) {
    // Arrange
    Range r("[23,45)");
    int ar[4] = { 23, 12, 26, -4 };

    // Act & Assert
    EXPECT_FALSE(r.IntegerRangeContains(ar, 4));
}

TEST(Guseva_Catherine_RangeTest, Contain_Integer_Interval_By_String) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    EXPECT_TRUE(r.ContainsRange("(30,40)"));
}

TEST(Guseva_Catherine_RangeTest, No_Contain_Integer_Interval_By_String) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    EXPECT_FALSE(r.ContainsRange("(30,50)"));
}

TEST(Guseva_Catherine_RangeTest, Overlaps_Range) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    EXPECT_TRUE(r.OverlapsRange("[10,30)"));
}

TEST(Guseva_Catherine_RangeTest, No_Overlaps_Range) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    EXPECT_FALSE(r.OverlapsRange("(10,20)"));
}

TEST(Guseva_Catherine_RangeTest, Equal_Intervals) {
    // Arrange
    Range r("[23,45)");
    Range r1("[23,45)");

    // Act & Assert
    EXPECT_TRUE(r == r1);
}

TEST(Guseva_Catherine_RangeTest, No_Equal_Intervals) {
    // Arrange
    Range r("[23,45)");
    Range r1("[13,25)");

    // Act & Assert
    EXPECT_TRUE(r != r1);
}

TEST(Guseva_Catherine_RangeTest, Can_Set_First) {
    // Arrange
    Range r("[23,45)");

    // Act
    r.SetFirst(13);

    // Assert
    EXPECT_EQ(13, r.GetFirst());
}

TEST(Guseva_Catherine_RangeTest, Can_Set_Second) {
    // Arrange
    Range r("[23,45)");

    // Act
    r.SetSecond(30);

    // Assert
    EXPECT_EQ(29, r.GetSecond());
}

TEST(Guseva_Catherine_RangeTest, Exepction_Wrong_First_Bracket) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Range r("23,45"));
}

TEST(Guseva_Catherine_RangeTest, Exepction_Wrong_Last_Bracket) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Range r("[23,45"));
}

TEST(Guseva_Catherine_RangeTest, Exepction_Wrong_Numbers) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Range r("[45,23)"));
}

TEST(Guseva_Catherine_RangeTest, Exepction_Set_First_Number) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    ASSERT_ANY_THROW(r.SetFirst(50));
}

TEST(Guseva_Catherine_RangeTest, Exepction_Set_Second_Number) {
    // Arrange
    Range r("[23,45)");

    // Act & Assert
    ASSERT_ANY_THROW(r.SetSecond(5));
}

TEST(Guseva_Catherine_RangeTest, Can_Copy_Range) {
    // Arrange
    Range r("[23,45)");

    // Act
    Range r1(r);

    // Assert
    EXPECT_TRUE(r == r1);
}
