// Copyright 2019 Kasmazyuk Nikita

#include "include/mass_converter.h"
#include "include/mass_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

void MassCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a mass calculator application.\n" +
        "Please provide arguments in the following format:\n" +

        "  $ " + appname + " <value> <operation>\n" +

        "Value have to be a double-precision number, " +
        "and number operation is one of the following:\n" +
        "'TonsToKilograms',\n" +
        "'TonsToGrams',\n" +
        "'TonsToMilligrams',\n" +
        "'TonsToPounds',\n" +
        "'TonsToOunces',\n" +
        "'KilogramsToTons',\n" +
        "'KilogramsToGrams',\n" +
        "'KilogramsToPounds',\n" +
        "'KilogramsToMilligrams',\n" +
        "'KilogramsToOunces',\n" +
        "'GramsToKilograms',\n" +
        "'GramsToTons',\n" +
        "'GramsToMilligrams',\n" +
        "'GramsToOunces',\n" +
        "'GramsToPounds',\n" +
        "'MilligramsToTons',\n" +
        "'MilligramsToOunces',\n" +
        "'MilligramsToGrams',\n" +
        "'MilligramsToKilograms',\n" +
        "'MilligramsToPounds',\n" +
        "'OuncesToTons',\n" +
        "'OuncesToGrams',\n" +
        "'OuncesToMilligrams',\n" +
        "'OuncesToKilograms',\n" +
        "'OuncesToPounds',\n" +
        "'PoundsToTons',\n" +
        "'PoundsToGrams',\n" +
        "'PoundsToOunces',\n" +
        "'PoundsToMilligrams',\n" +
        "'PoundsToKilograms'.\n";
}

bool MassCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 2 arguments.\n");
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


std::string parseOperation(const char* arg) {
    std::string op;
    enum {
    TonsToKillograms = 1,
    TonsToGrams,
    TonsToMilligrams,
    TonsToPounds,
    TonsToOunces,
    KilogramsToTons,
    KilogramsToGrams,
    KilogramsToPounds,
    KilogramsToMilligrams,
    KilogramsToOunces,
    GramsToKilograms,
    GramsToTons,
    GramsToMilligrams,
    GramsToOunces,
    GramsToPounds,
    MilligramsToTons,
    MilligramsToOunces,
    MilligramsToGrams,
    MilligramsToKilograms,
    MilligramsToPounds,
    OuncesToTons,
    OuncesToGrams,
    OuncesToMilligrams,
    OuncesToKilograms,
    OuncesToPounds,
    PoundsToTons,
    PoundsToGrams,
    PoundsToOunces,
    PoundsToMilligrams,
    PoundsToKilograms
    };

    if (strcmp(arg, "TonsToKilograms") == 0) {
        op = std::to_string(static_cast<int>(TonsToKillograms));
    } else if (strcmp(arg, "TonsToGrams") == 0) {
        op = std::to_string(static_cast<int>(TonsToGrams));
    } else if (strcmp(arg, "TonsToMilligrams") == 0) {
        op = std::to_string(static_cast<int>(TonsToMilligrams));
    } else if (strcmp(arg, "TonsToPounds") == 0) {
        op = std::to_string(static_cast<int>(TonsToPounds));
    } else if (strcmp(arg, "TonsToOunces") == 0) {
        op = std::to_string(static_cast<int>(TonsToOunces));
    } else if (strcmp(arg, "KilogramsToTons") == 0) {
        op = std::to_string(static_cast<int>(KilogramsToTons));
    } else if (strcmp(arg, "KilogramsToGrams") == 0) {
        op = std::to_string(static_cast<int>(KilogramsToGrams));
    } else if (strcmp(arg, "KilogramsToPounds") == 0) {
        op = std::to_string(static_cast<int>(KilogramsToPounds));
    } else if (strcmp(arg, "KilogramsToMilligrams") == 0) {
        op = std::to_string(static_cast<int>(KilogramsToMilligrams));
    } else if (strcmp(arg, "KilogramsToOunces") == 0) {
        op = std::to_string(static_cast<int>(KilogramsToOunces));
    } else if (strcmp(arg, "GramsToKilograms") == 0) {
        op = std::to_string(static_cast<int>(GramsToKilograms));
    } else if (strcmp(arg, "GramsToTons") == 0) {
        op = std::to_string(static_cast<int>(GramsToTons));
    } else if (strcmp(arg, "GramsToMilligrams") == 0) {
        op = std::to_string(static_cast<int>(GramsToMilligrams));
    } else if (strcmp(arg, "GramsToOunces") == 0) {
        op = std::to_string(static_cast<int>(GramsToOunces));
    } else if (strcmp(arg, "GramsToPounds") == 0) {
        op = std::to_string(static_cast<int>(GramsToPounds));
    } else if (strcmp(arg, "MilligramsToTons") == 0) {
        op = std::to_string(static_cast<int>(MilligramsToTons));
    } else if (strcmp(arg, "MilligramsToOunces") == 0) {
        op = std::to_string(static_cast<int>(MilligramsToOunces));
    } else if (strcmp(arg, "MilligramsToGrams") == 0) {
        op = std::to_string(static_cast<int>(MilligramsToGrams));
    } else if (strcmp(arg, "MilligramsToKilograms") == 0) {
        op = std::to_string(static_cast<int>(MilligramsToKilograms));
    } else if (strcmp(arg, "MilligramsToPounds") == 0) {
        op = std::to_string(static_cast<int>(MilligramsToPounds));
    } else if (strcmp(arg, "OuncesToTons") == 0) {
        op = std::to_string(static_cast<int>(OuncesToTons));
    } else if (strcmp(arg, "OuncesToGrams") == 0) {
        op = std::to_string(static_cast<int>(OuncesToGrams));
    } else if (strcmp(arg, "OuncesToMilligrams") == 0) {
        op = std::to_string(static_cast<int>(OuncesToMilligrams));
    } else if (strcmp(arg, "OuncesToKilograms") == 0) {
        op = std::to_string(static_cast<int>(OuncesToKilograms));
    } else if (strcmp(arg, "OuncesToPounds") == 0) {
        op = std::to_string(static_cast<int>(OuncesToPounds));
    } else if (strcmp(arg, "PoundsToTons") == 0) {
        op = std::to_string(static_cast<int>(PoundsToTons));
    } else if (strcmp(arg, "PoundsToGrams") == 0) {
        op = std::to_string(static_cast<int>(PoundsToGrams));
    } else if (strcmp(arg, "PoundsToOunces") == 0) {
        op = std::to_string(static_cast<int>(PoundsToOunces));
    } else if (strcmp(arg, "PoundsToMilligrams") == 0) {
        op = std::to_string(static_cast<int>(PoundsToMilligrams));
    } else if (strcmp(arg, "PoundsToKilograms") == 0) {
        op = std::to_string(static_cast<int>(PoundsToKilograms));

    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string MassCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (args.operation == "1") {
        stream << "Kilograms: " << MassConverter::TonsToKilograms(args.value);
    } else if (args.operation == "2") {
        stream << "Grams: " << MassConverter::TonsToGrams(args.value);
    } else if (args.operation == "3") {
        stream << "Milligrams: " << MassConverter::TonsToMilligrams(args.value);
    } else if (args.operation == "4") {
        stream << "Pounds: " << MassConverter::TonsToPounds(args.value);
    } else if (args.operation == "5") {
        stream << "Ounces: " << MassConverter::TonsToOunces(args.value);
    } else if (args.operation == "6") {
        stream << "Tons: " << MassConverter::KilogramsToTons(args.value);
    } else if (args.operation == "7") {
        stream << "Grams: " << MassConverter::KilogramsToGrams(args.value);
    } else if (args.operation == "8") {
        stream << "Pounds: " << MassConverter::KilogramsToPounds(args.value);
    } else if (args.operation == "9") {
        stream << "Milligrams: ";
        stream << MassConverter::KilogramsToMilligrams(args.value);
    } else if (args.operation == "10") {
        stream << "Ounces: " << MassConverter::KilogramsToOunces(args.value);
    } else if (args.operation == "11") {
        stream << "Kilograms: " << MassConverter::GramsToKilograms(args.value);
    } else if (args.operation == "12") {
        stream << "Tons: " << MassConverter::GramsToTons(args.value);
    } else if (args.operation == "13") {
        stream << "Milligrams: ";
        stream<< MassConverter::GramsToMilligrams(args.value);
    } else if (args.operation == "14") {
        stream << "Ounces: " << MassConverter::GramsToOunces(args.value);
    } else if (args.operation == "15") {
        stream << "Pounds: " << MassConverter::GramsToPounds(args.value);
    } else if (args.operation == "16") {
        stream << "Tons: " << MassConverter::MilligramsToTons(args.value);
    } else if (args.operation == "17") {
        stream << "Ounces: " << MassConverter::MilligramsToOunces(args.value);
    } else if (args.operation == "18") {
        stream << "Grams: " << MassConverter::MilligramsToGrams(args.value);
    } else if (args.operation == "19") {
        stream << "Kilograms: ";
        stream << MassConverter::MilligramsToKilograms(args.value);
    } else if (args.operation == "20") {
        stream << "Pounds: " << MassConverter::MilligramsToPounds(args.value);
    } else if (args.operation == "21") {
        stream << "Tons: " << MassConverter::OuncesToTons(args.value);
    } else if (args.operation == "22") {
        stream << "Grams: " << MassConverter::OuncesToGrams(args.value);
    } else if (args.operation == "23") {
        stream << "Milligrams: ";
        stream << MassConverter::OuncesToMilligrams(args.value);
    } else if (args.operation == "24") {
        stream << "Kilograms: " << MassConverter::OuncesToKilograms(args.value);
    } else if (args.operation == "25") {
        stream << "Pounds: " << MassConverter::OuncesToPounds(args.value);
    } else if (args.operation == "26") {
        stream << "Tons: " << MassConverter::PoundsToTons(args.value);
    } else if (args.operation == "27") {
        stream << "Grams: " << MassConverter::PoundsToGrams(args.value);
    } else if (args.operation == "28") {
        stream << "Ounces: " << MassConverter::PoundsToOunces(args.value);
    } else if (args.operation == "29") {
        stream << "Milligrams: ";
        stream << MassConverter::PoundsToMilligrams(args.value);
    } else if (args.operation == "30") {
        stream << "Kilograms: " << MassConverter::PoundsToKilograms(args.value);
    }

    message_ = stream.str();

    return message_;
}
