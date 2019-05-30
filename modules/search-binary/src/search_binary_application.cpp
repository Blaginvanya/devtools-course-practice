// Copyright 2019 Druzhinin Alexei

#include "include/search_binary.h"
#include "include/search_binary_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

SearchBinaryApplication::SearchBinaryApplication() : message_("") {}

void SearchBinaryApplication::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a binary search application.\n" +
          "Please provide arguments in the following format:\n\n"+
          "  $ " + appname + " <size of array> " +
          "<item> " + "<array>\n\n" +
          "Warning!" +
          " All arguments are integers. The array must be sorted.\n";
}

int ParseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);
    if (end[0]) {
        throw std::string("Wrong number format!\n\n");
    }
    return value;
}

bool SearchBinaryApplication::ValidateNumberOfArguments(int argc,
                                                        const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else {
        try {
            size = ParseInt(argv[1]);
        }
        catch(std::string& str) {
            Help(argv[0], "Wrong number format in size!");
            return false;
        }
        if (argc != size + 3) {
            Help(argv[0],
            "ERROR: Check count of arguments and size of entered array.\n\n");
            return false;
        }
    }
    try {
        item = ParseInt(argv[2]);
    }
    catch(std::string& str) {
        Help(argv[0], "Wrong number format in item!");
        return false;
    }
    return true;
}

bool CheckSort(const int size, const int* array) {
    int i;
    for (i = 0; i < size - 1; i++)
        if (array[i] > array[i + 1])
            break;

    if (i == size - 1)
        return true;
    else
        return false;
}

std::string SearchBinaryApplication::operator()(int argc, const char** argv) {
    std::ostringstream stream;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (size < 1) {
        message_ = "ERROR: Size must be >= 1";
        return message_;
    }

    array = new int[size];

    try {
        for (int i = 0; i < size; i++) {
            array[i] = ParseInt(argv[i + 3]);
        }
    } catch(std::string& str) {
        delete[] array;
        return str;
    }

    if (CheckSort(size, array)) {
        double result;
        SearchBinary sb;
        result = sb.Search(item, array, size);
        if (result == -1) {
            stream << "Item not found";
        } else {
            stream << "Index of the item = " << result;
        }
    } else {
        stream << "Error! Array not sorted";
    }

    message_ = stream.str();
    delete[] array;

    return message_;
}
