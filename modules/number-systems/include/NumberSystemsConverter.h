// This class represents a number which is being stored in differents number
// systems at the same time.
// It is necessary to indicate the base number system when you create an object
// (the parameter of constructor).
// Copyright 2019 Fedotov Vlad

#ifndef MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBERSYSTEMSCONVERTER_H_
#define MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBERSYSTEMSCONVERTER_H_
#include <string>

enum SysBase {BIN, OCT, HEX};

class NumberSystemsConverter {
 public:
    explicit NumberSystemsConverter(std::string input_number = "0",
                           SysBase input_base = BIN);
    NumberSystemsConverter(const NumberSystemsConverter &n);
    NumberSystemsConverter& operator=(const NumberSystemsConverter& n);

    std::string GetNumberInBin() const;
    std::string GetNumberInOct() const;
    std::string GetNumberInHex() const;

    NumberSystemsConverter operator+ (const NumberSystemsConverter& z) const;

    bool operator== (const NumberSystemsConverter& n) const;
    bool operator!= (const NumberSystemsConverter& n) const;

 private:
    std::string NumberInBin;
    std::string NumberInOct;
    std::string NumberInHex;

    std::string ConvertBinToOct(const std::string n);
    std::string ConvertBinToHex(const std::string n);
    std::string ConvertOctToBin(const std::string n);
    std::string ConvertHexToBin(const std::string n);
    std::string CutFrontZeros(const std::string n);
    friend std::string ConvertBinToDec(const std::string &n);
    friend std::string ConvertDecToBin(const std::string &n);
};

std::string ConvertBinToDec(const std::string &n);
std::string ConvertDecToBin(const std::string &n);

#endif  // MODULES_NUMBER_SYSTEMS_INCLUDE_NUMBERSYSTEMSCONVERTER_H_
