// Copyright 2019 Ivan Yunin

#include "include/temperature_converter.h"
#include "include/temperature_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

void TemperatureCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a temperature calculator application.\n" +
          "Please provide arguments in the following format:\n"+

          "  $ " + appname + " <value> <operation>\n" +

          "Value have to be a double-precision number, " +
          "and <operation> is one of the following:\n" +
          "'CelsiusToFahrenheit',\n" +
          "'CelsiusToKelvin',\n" +
          "'CelsiusToNewton',\n" +
          "'FahrenheitToCelsius',\n" +
          "'KelvinToCelsius',\n" +
          "'NewtonToCelsius'.\n";
}

bool TemperatureCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
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
    if (strcmp(arg, "CelsiusToFahrenheit") == 0) {
        op = "CelsiusToFahrenheit";
    } else if (strcmp(arg, "CelsiusToKelvin") == 0) {
        op = "CelsiusToKelvin";
    } else if (strcmp(arg, "CelsiusToNewton") == 0) {
        op = "CelsiusToNewton";
    } else if (strcmp(arg, "FahrenheitToCelsius") == 0) {
        op = "FahrenheitToCelsius";
    } else if (strcmp(arg, "KelvinToCelsius") == 0) {
        op = "KelvinToCelsius";
    } else if (strcmp(arg, "NewtonToCelsius") == 0) {
        op = "NewtonToCelsius";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string TemperatureCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (args.operation == "CelsiusToFahrenheit") {
        stream << "Fahrenheit: " <<
        TemperatureConverter::CelsiusToFahrenheit(args.value);
    } else if (args.operation == "CelsiusToKelvin") {
        stream << "Kelvin: " <<
        TemperatureConverter::CelsiusToKelvin(args.value);
    } else if (args.operation == "CelsiusToNewton") {
        stream << "Newton: " <<
        TemperatureConverter::CelsiusToNewton(args.value);
    } else if (args.operation == "FahrenheitToCelsius") {
        stream << "Celsius: " <<
        TemperatureConverter::FahrenheitToCelsius(args.value);
    } else if (args.operation == "KelvinToCelsius") {
        stream << "Celsius: " <<
        TemperatureConverter::KelvinToCelsius(args.value);
    } else if (args.operation == "NewtonToCelsius") {
        stream << "Celsius: " <<
        TemperatureConverter::NewtonToCelsius(args.value);
    }

    message_ = stream.str();

    return message_;
}
