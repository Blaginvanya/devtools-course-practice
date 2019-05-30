// Copyright 2019 Pinaev Danil

#include "include/romanumber.h"
#include "include/romanumber_converter.h"

#include <stdint.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

std::string RomaNumberConverter::Help(const char* appname) {
    return "This is application for roma number converter.\n"
        "Usage:\n"
        "Enter positive integer arabic or roma number.\n";
}

bool RomaNumberConverter::validateNumberOfArguments(int argc,
                                             const char** argv) {
    if (argc != 2) {
        return false;
    }

    if (!(converter_.IsArabStringCorrect(argv[1]) ||
        converter_.IsRomaStringCorrect(argv[1])))
        return false;

    return true;
}

std::string RomaNumberConverter::operator()(int argc, const char** argv) {
    RomaNumber converter;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return Help("");
    }

    if (converter.IsArabStringCorrect(argv[1])) {
        converter.ArabToRoma(atoi(argv[1]));

        stream << "Roma number is " << converter.GetRoma() << std::endl;
    } else if (converter.IsRomaStringCorrect(argv[1])) {
        converter.RomaToArab(std::string(argv[1]));

        stream << "Arabic number is " << converter.GetArabic() << std::endl;
    }

    message_ = stream.str();

    return message_;
}
