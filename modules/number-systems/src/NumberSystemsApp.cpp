// Copyright 2019 Zhivaev Artem

#include "include/NumberSystemsApp.h"

#include <string.h>

#include <sstream>
#include <string>

#include "include/NumberSystemsConverter.h"

void NumberSystemsApp::Help(const char *appname, const char *message) {
    message_ = std::string(message) +
        "This is a number systems converter.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <number> <system base src> <system base dst>" +
        "\n\n" +
        "Where <system base> is 'BIN', 'OCT' or 'HEX'.\n";
}

bool NumberSystemsApp::ValidateNumberOfArgs(int argc, const char **argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    } else {
        return true;
    }
}

SysBase parseSysBase(const char *arg) {
    if (strcmp("BIN", arg) == 0) {
        return BIN;
    } else if (strcmp("OCT", arg) == 0) {
        return OCT;
    } else if (strcmp("HEX", arg) == 0) {
        return HEX;
    } else {
        throw std::string("Wrong system base format!");
    }
}

std::string NumberSystemsApp::operator()(int argc, const char **argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.number = argv[1];
        args.sb1    = parseSysBase(argv[2]);
        args.sb2    = parseSysBase(argv[3]);
    } catch (std::string &e) {
        return e;
    }

    NumberSystemsConverter num;
    try {
        num = NumberSystemsConverter(args.number, args.sb1);
    } catch (const char *e) {
        return std::string(e);
    }

    std::ostringstream oss;

    switch (args.sb1) {
      case BIN:
        oss << "BIN: ";
        break;
      case OCT:
        oss << "OCT: ";
        break;
      case HEX:
        oss << "HEX: ";
        break;
    }
    oss << args.number << '\n';

    switch (args.sb2) {
      case BIN:
        oss << "BIN: " << num.GetNumberInBin();
        break;
      case OCT:
        oss << "OCT: " << num.GetNumberInOct();
        break;
      case HEX:
        oss << "HEX: " << num.GetNumberInHex();
        break;
    }

    message_ = oss.str();

    return message_;
}


