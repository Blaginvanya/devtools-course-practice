// Copyright 2019 Muravev Denis

#include "include/bit_array_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

BitArrayApplication::BitArrayApplication() : message_("") {}

void BitArrayApplication::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a bit array application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <type_data> <data> " +
          "<operation> <set_val1> <set_val2> ...\n\n" +

          "Where all arguments are int numbers, " +
          "type data: create('c') or modify('m') bit array, " +
          "and <operation> is one of add('a'), del('d').\n";
}

bool BitArrayApplication::ValidateArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc < 5) {
        Help(argv[0], "ERROR: There must be at least 4 arguments.\n\n");
        return false;
    }
    return true;
}

char ParseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "c") == 0) {
        op = 'c';
    } else if (strcmp(arg, "m") == 0) {
        op = 'm';
    } else if (strcmp(arg, "a") == 0) {
        op = 'a';
    } else if (strcmp(arg, "d") == 0) {
        op = 'd';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string BitArrayApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateArguments(argc, argv)) {
        return message_;
    }
    try {
        args.type_data = ParseOperation(argv[1]);
        args.data = argv[2];
        args.operation = ParseOperation(argv[3]);
        for (int i = 4; i < argc; i++)
            args.set_value.push_back(atoi(argv[i]));
    }
    catch(std::string& str) {
        return str;
    }

    BitArray bit;
    if (args.type_data == 'c') {
        bit = BitArray(atoi(args.data.c_str()));
    } else if (args.type_data == 'm') {
        bit = BitArray(args.data.length());
        for (unsigned int i = 0; i < args.data.length(); i++)
            if (args.data[i] == '1') {
                bit.SetBit(i, true);
            }
    }
    bool mode = false;
    if (args.operation == 'a') {
        mode = true;
    }
    for (unsigned int i = 0; i < args.set_value.size(); i++) {
        bit.SetBit(args.set_value[i], mode);
    }

    std::ostringstream stream;

    stream << "Res bit array = " << bit.print_string();

    message_ = stream.str();

    return message_;
}
