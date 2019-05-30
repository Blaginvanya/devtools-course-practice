// Copyright 2019 Kasmazyuk Nikita

#include <gtest/gtest.h>
#include "include/Money_Converter.h"

TEST(MoneyConverterTest, Can_Rubles_To_Euro) {
    // Arrange
    MoneyConverter converter;
    double input = 72.29;
    double output;

    // Act
    output = converter.RublesToEuro(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Rubles_To_Dollar) {
    // Arrange
    MoneyConverter converter;
    double input = 64.82;
    double output;

    // Act
    output = converter.RublesToDollar(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Rubles_To_Shekel) {
    // Arrange
    MoneyConverter converter;
    double input = 17.9;
    double output;

    // Act
    output = converter.RublesToShekel(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Rubles_To_Grivna) {
    // Arrange
    MoneyConverter converter;
    double input = 2.45;
    double output;

    // Act
    output = converter.RublesToGrivna(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Rubles_To_Dirham) {
    // Arrange
    MoneyConverter converter;
    double input = 17.65;
    double output;

    // Act
    output = converter.RublesToDirham(input);

    // Assert
    EXPECT_NEAR(1.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Euro_To_Dirham) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.EuroToDirham(input);

    // Assert
    EXPECT_NEAR(409.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Euro_To_Grivna) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.EuroToGrivna(input);

    // Assert
    EXPECT_NEAR(2953.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Euro_To_Shekel) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.EuroToShekel(input);

    // Assert
    EXPECT_NEAR(403.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Euro_To_Rubles) {
    // Arrange
    MoneyConverter converter;
    double input = 1.0;
    double output;

    // Act
    output = converter.EuroToRubles(input);

    // Assert
    EXPECT_NEAR(72.24, output, 0.01);
}

TEST(MoneyConverterTest, Can_Euro_To_Dollar) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.EuroToDollar(input);

    // Assert
    EXPECT_NEAR(111.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dollar_To_Euro) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DollarToEuro(input);

    // Assert
    EXPECT_NEAR(89.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dollar_To_Rubles) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DollarToRubles(input);

    // Assert
    EXPECT_NEAR(6482.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dollar_To_Shekel) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DollarToShekel(input);

    // Assert
    EXPECT_NEAR(362.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dollar_To_Dirham) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DollarToDirham(input);

    // Assert
    EXPECT_NEAR(367.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dollar_To_Grivna) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DollarToGrivna(input);

    // Assert
    EXPECT_NEAR(2647.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Shekel_To_Grivna) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.ShekelToGrivna(input);

    // Assert
    EXPECT_NEAR(731.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Shekel_To_Dirham) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.ShekelToDirham(input);

    // Assert
    EXPECT_NEAR(1010.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Shekel_To_Rubles) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.ShekelToRubles(input);

    // Assert
    EXPECT_NEAR(1788.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Shekel_To_Dollar) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.ShekelToDollar(input);

    // Assert
    EXPECT_NEAR(276.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Shekel_To_Euro) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.ShekelToEuro(input);

    // Assert
    EXPECT_NEAR(246.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dirham_To_Dollar) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.DirhamToDollar(input);

    // Assert
    EXPECT_NEAR(273.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dirham_To_Grivna) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DirhamToGrivna(input);

    // Assert
    EXPECT_NEAR(720.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dirham_To_Shekel) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.DirhamToShekel(input);

    // Assert
    EXPECT_NEAR(98.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dirham_To_Euro) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.DirhamToEuro(input);

    // Assert
    EXPECT_NEAR(243.0, output, 0.01);
}

TEST(MoneyConverterTest, Can_Dirham_To_Rubles) {
    // Arrange
    MoneyConverter converter;
    double input = 1.0;
    double output;

    // Act
    output = converter.DirhamToRubles(input);

    // Assert
    EXPECT_NEAR(17.63, output, 0.01);
}

TEST(MoneyConverterTest, Can_Grivna_To_Dollar) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.GrivnaToDollar(input);

    // Assert
    EXPECT_NEAR(3.7, output, 0.01);
}

TEST(MoneyConverterTest, Can_Grivna_To_Euro) {
    // Arrange
    MoneyConverter converter;
    double input = 100.0;
    double output;

    // Act
    output = converter.GrivnaToEuro(input);

    // Assert
    EXPECT_NEAR(3.3, output, 0.01);
}

TEST(MoneyConverterTest, Can_Grivna_To_Rubles) {
    // Arrange
    MoneyConverter converter;
    double input = 1.0;
    double output;

    // Act
    output = converter.GrivnaToRubles(input);

    // Assert
    EXPECT_NEAR(2.443, output, 0.01);
}

TEST(MoneyConverterTest, Can_Grivna_To_Dirham) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.GrivnaToDirham(input);

    // Assert
    EXPECT_NEAR(138.0, output, 0.1);
}

TEST(MoneyConverterTest, Can_Grivna_To_Shekel) {
    // Arrange
    MoneyConverter converter;
    double input = 1000.0;
    double output;

    // Act
    output = converter.GrivnaToShekel(input);

    // Assert
    EXPECT_NEAR(136.0, output, 0.01);
}
