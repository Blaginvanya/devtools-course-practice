// Copyright 2019 Karasev Anton

#include "include/fibonacci_heap_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

FibonacciHeapApplication::FibonacciHeapApplication() : message_("") {}

void FibonacciHeapApplication::Help(const char* appname, const char* message) {
    message_ =
    std::string(message) +
    "This is a fibonacci heap application.\n\n" +
    "Please provide arguments in the following format:\n\n"+
    "  $ " + appname + "<operation> <find_elem> <val1> ...\n\n" +
    "Where all arguments are int numbers, " +
    "and <operation> is one of 'min', 'find', 'merge',"
    + "find_el - number in operation find.\n";
}

bool FibonacciHeapApplication::valNumOfArg(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc < 4) {
        Help(argv[0], "ERROR: There must be at least 4 arguments.\n\n");
        return false;
    }
    return true;
}

char ParseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "min") == 0) {
        op = 'm';
    } else if (strcmp(arg, "find") == 0) {
        op = 'f';
    } else if (strcmp(arg, "merge") == 0) {
        op = 'M';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string FibonacciHeapApplication::operator()(int argc, const char** argv) {
    Arguments args;
    int find_el, size_v = 0;

    if (!valNumOfArg(argc, argv)) {
        return this->message_;
    }
    try {
        args.operation_ = ParseOperation(argv[1]);
        find_el = atoi(argv[2]);
        for (int i = 3; i < argc; i++) {
            args.weights_.push_back(atoi(argv[i]));
            size_v++;
        }
    }
    catch(std::string& str) {
        return str;
    }

    FibonacciHeap h1, h2;
    Node *tmp = nullptr;

    std::ostringstream stream;

    switch (args.operation_) {
     case 'm':
        for (int i = 0; i < size_v; ++i) {
             h1.Insert(args.weights_[i]);
        }
        stream << "Min = " << h1.GetMinimum();
        break;
     case 'f':
         for (int i = 0; i < size_v; ++i) {
             h1.Insert(args.weights_[i]);
        }
        tmp = h1.Find(find_el);
        if (tmp != nullptr) {
        stream << find_el << " is found in heap";
        } else {
        stream << find_el << " not found in heap";
        }
        break;
     case 'M':
        for (int i = 0; i < size_v; ++i) {
             h1.Insert(args.weights_[i]);
        }
        h1.Merge(h2);
        if (!h1.IsEmpty()) {
        stream << "Merge successfully";
        }
        break;
    }

    this->message_ = stream.str();

    return this->message_;
}
