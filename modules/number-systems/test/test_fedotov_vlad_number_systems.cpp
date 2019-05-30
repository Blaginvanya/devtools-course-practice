// Copyright 2019 Fedotov Vlad

#include <gtest/gtest.h>
#include <string>
#include "include/NumberSystemsConverter.h"

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_No_Arguments) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter());
}

TEST(Fedotov_Vlad_NumberSystemsConverter,
     Can_Create_With_No_Arguments_Correctly) {
    // Act & Assert
    NumberSystemsConverter conv;
    EXPECT_EQ("0", conv.GetNumberInBin());
    EXPECT_EQ("0", conv.GetNumberInHex());
    EXPECT_EQ("0", conv.GetNumberInOct());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_One_Argument) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter("1010"));
}

TEST(Fedotov_Vlad_NumberSystemsConverter,
     Can_Create_With_One_Argument_Correctly) {
    // Act & Assert
    NumberSystemsConverter conv("1010");
    EXPECT_EQ("1010", conv.GetNumberInBin());
    EXPECT_EQ("12", conv.GetNumberInOct());
    EXPECT_EQ("A", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_Two_Arguments_BIN) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter("1010", BIN));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_Two_Arguments_OCT) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter("7", OCT));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Can_Create_With_Two_Arguments_HEX) {
    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter("A", HEX));
}

TEST(Fedotov_Vlad_NumberSystemsConverter,
     Can_Create_With_Two_Arguments_Correctly) {
    // Act & Assert
    NumberSystemsConverter conv("1010", BIN);
    EXPECT_EQ("1010", conv.GetNumberInBin());
    EXPECT_EQ("12", conv.GetNumberInOct());
    EXPECT_EQ("A", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCopy) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);

    // Act & Assert
    ASSERT_NO_THROW(NumberSystemsConverter copyconv(conv));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCopyCorrectly) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);

    // Act
    NumberSystemsConverter copyconv(conv);
    // Assert
    EXPECT_EQ(conv.GetNumberInBin(), copyconv.GetNumberInBin());
    EXPECT_EQ(conv.GetNumberInOct(), copyconv.GetNumberInOct());
    EXPECT_EQ(conv.GetNumberInHex(), copyconv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanAssign) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);

    // Act & Assert
    ASSERT_NO_THROW(conv = conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanAssignCorrectly) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);

    // Act
    conv = conv2;

    // Assert
    EXPECT_EQ(conv2.GetNumberInBin(), conv.GetNumberInBin());
    EXPECT_EQ(conv2.GetNumberInOct(), conv.GetNumberInOct());
    EXPECT_EQ(conv2.GetNumberInHex(), conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, NoThrowWhenAssignsItself) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);

    // Act and Assert
    ASSERT_NO_THROW(conv = conv);
}

/*TEST(Fedotov_Vlad_NumberSystemsConverter, DISABLED_CanCompare) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);
    // bool flag;

    // Act & Assert
    ASSERT_NO_THROW(conv == conv2);
}*/

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCompareCorrectly_1) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);
    bool flag;

    // Act & Assert
    EXPECT_FALSE(flag = conv == conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanCompareCorrectly_2) {
    // Arrange
    NumberSystemsConverter conv("10", BIN);
    NumberSystemsConverter conv2("11", BIN);
    bool flag;

    // Act & Assert
    EXPECT_TRUE(flag = conv != conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_1) {
    // Act & Assert
    NumberSystemsConverter conv("1", BIN);
    EXPECT_EQ("1", conv.GetNumberInBin());
    EXPECT_EQ("1", conv.GetNumberInOct());
    EXPECT_EQ("1", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_2) {
    // Act & Assert
    NumberSystemsConverter conv("1000", BIN);
    EXPECT_EQ("1000", conv.GetNumberInBin());
    EXPECT_EQ("10", conv.GetNumberInOct());
    EXPECT_EQ("8", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_3) {
    // Act & Assert
    NumberSystemsConverter conv("0", BIN);
    EXPECT_EQ("0", conv.GetNumberInBin());
    EXPECT_EQ("0", conv.GetNumberInOct());
    EXPECT_EQ("0", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_4) {
    // Act & Assert
    NumberSystemsConverter conv("11111111", BIN);
    EXPECT_EQ("11111111", conv.GetNumberInBin());
    EXPECT_EQ("377", conv.GetNumberInOct());
    EXPECT_EQ("FF", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_5) {
    // Act & Assert
    NumberSystemsConverter conv("110110", BIN);
    EXPECT_EQ("110110", conv.GetNumberInBin());
    EXPECT_EQ("66", conv.GetNumberInOct());
    EXPECT_EQ("36", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertBinToOctAndHex_6) {
    // Act & Assert
    NumberSystemsConverter conv("01000101011011011110", BIN);
    EXPECT_EQ("1000101011011011110", conv.GetNumberInBin());
    EXPECT_EQ("1053336", conv.GetNumberInOct());
    EXPECT_EQ("456DE", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Does_Throw_When_Wrong_Bin) {
    // Act & Assert
    ASSERT_ANY_THROW(NumberSystemsConverter conv("11010131", BIN));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_1) {
    // Act & Assert
    NumberSystemsConverter conv("1", OCT);
    EXPECT_EQ("1", conv.GetNumberInBin());
    EXPECT_EQ("1", conv.GetNumberInOct());
    EXPECT_EQ("1", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_2) {
    // Act & Assert
    NumberSystemsConverter conv("10", OCT);
    EXPECT_EQ("1000", conv.GetNumberInBin());
    EXPECT_EQ("10", conv.GetNumberInOct());
    EXPECT_EQ("8", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_3) {
    // Act & Assert
    NumberSystemsConverter conv("010", OCT);
    EXPECT_EQ("1000", conv.GetNumberInBin());
    EXPECT_EQ("10", conv.GetNumberInOct());
    EXPECT_EQ("8", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertOctToBinAndHex_4) {
    // Act & Assert
    NumberSystemsConverter conv("023456", OCT);
    EXPECT_EQ("10011100101110", conv.GetNumberInBin());
    EXPECT_EQ("23456", conv.GetNumberInOct());
    EXPECT_EQ("272E", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Does_Throw_When_Wrong_Oct) {
    // Act & Assert
    ASSERT_ANY_THROW(NumberSystemsConverter conv("128", OCT));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertHexToBinAndOct_1) {
    // Act & Assert
    NumberSystemsConverter conv("ABC", HEX);
    EXPECT_EQ("101010111100", conv.GetNumberInBin());
    EXPECT_EQ("5274", conv.GetNumberInOct());
    EXPECT_EQ("ABC", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertHexToBinAndOct_2) {
    // Act & Assert
    NumberSystemsConverter conv("000ABC", HEX);
    EXPECT_EQ("101010111100", conv.GetNumberInBin());
    EXPECT_EQ("5274", conv.GetNumberInOct());
    EXPECT_EQ("ABC", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, ConvertHexToBinAndOct_3) {
    // Act & Assert
    NumberSystemsConverter conv("0000000000000123456789DEF", HEX);
    EXPECT_EQ("100100011010001010110011110001001110111101111",
        conv.GetNumberInBin());
    EXPECT_EQ("443212636116757", conv.GetNumberInOct());
    EXPECT_EQ("123456789DEF", conv.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, Does_Throw_When_Wrong_Hex) {
    // Act & Assert
    ASSERT_ANY_THROW(NumberSystemsConverter conv("GHIJ", HEX));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanConvertBinToDec_1) {
    // Arrange
    std::string bin = "1010";
    std::string dec = "10";
    // Act & Assert
    EXPECT_EQ(dec, ConvertBinToDec(bin));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanConvertBinToDec_2) {
    // Arrange
    std::string bin = "11111111";
    std::string dec = "255";
    // Act & Assert
    EXPECT_EQ(dec, ConvertBinToDec(bin));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanConvertDecToBin_1) {
    // Arrange
    std::string dec = "10";
    std::string bin = "1010";
    // Act & Assert
    EXPECT_EQ(bin, ConvertDecToBin(dec));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanConvertDecToBin_2) {
    // Arrange
    std::string dec = "255";
    std::string bin = "11111111";
    // Act & Assert
    EXPECT_EQ(bin, ConvertDecToBin(dec));
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanSum) {
    // Arrange
    NumberSystemsConverter conv1("1010", BIN);  //  10 in dec
    NumberSystemsConverter conv2("17", OCT);  //  15 in dec

    // Act & Assert
    ASSERT_NO_THROW(conv1 + conv2);
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanSumCorrectly_1) {
    // Arrange
    NumberSystemsConverter conv1("1010", BIN);  //  10 in dec
    NumberSystemsConverter conv2("17", OCT);  //  15 in dec

    // Act
    NumberSystemsConverter convres = conv1 + conv2;

    // Assert
    EXPECT_EQ("11001", convres.GetNumberInBin());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanSumCorrectly_2) {
    // Arrange
    NumberSystemsConverter conv1("1010", BIN);  //  10 in dec
    NumberSystemsConverter conv2("17", OCT);  //  15 in dec

    // Act
    NumberSystemsConverter convres = conv1 + conv2;

    // Assert
    EXPECT_EQ("31", convres.GetNumberInOct());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CanSumCorrectly_3) {
    // Arrange
    NumberSystemsConverter conv1("1010", BIN);  //  10 in dec
    NumberSystemsConverter conv2("17", OCT);  //  15 in dec

    // Act
    NumberSystemsConverter convres = conv1 + conv2;

    // Assert
    EXPECT_EQ("19", convres.GetNumberInHex());
}

TEST(Fedotov_Vlad_NumberSystemsConverter, CutFrontZeros) {
    // Act & Assert
    NumberSystemsConverter conv("010", OCT);
    EXPECT_EQ("1000", conv.GetNumberInBin());
    EXPECT_EQ("10", conv.GetNumberInOct());
    EXPECT_EQ("8", conv.GetNumberInHex());
}
