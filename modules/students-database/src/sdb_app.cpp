// Copyright 2019 Kutovoi Vadim

#include "include/sdb.h"
#include "include/sdb_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>


std::string SdbApp::Help(const char* appname) {
    return  std::string("This is a Student database application.\n\n") +
            "Please provide arguments in the following format:\n\n" +
            "  $ " + appname + " <operation> <arguments>\n\n" +
            "It Could be: \ntotal \ngood \nbad \naverage $(lastname)\n" +
            "remove $(lastname) \nadd $(firstname) $(lastname) \n" +
            "mark $(lastname) $(subject) $(value)";
}


std::string ParseOperation(const char* arg) {
    std::string op = "";
    if (strcmp(arg, "total") == 0) {
        op = "GET_NUMBER_STUDENTS";
    } else if (strcmp(arg, "good") == 0) {
        op = "GET_GOOD_STUDENTS";
    } else if (strcmp(arg, "bad") == 0) {
        op = "GET_BAD_STUDENTS";
    } else if (strcmp(arg, "add") == 0) {
        op = "ADD_STUDENT";
    } else if (strcmp(arg, "remove") == 0) {
        op = "REMOVE_STUDENT";
    } else if (strcmp(arg, "mark") == 0) {
        op = "ADD_MARK";
    } else if (strcmp(arg, "average") == 0) {
        op = "GET_AVG_MARK";
    } else {
        throw std::string("Unsupported operation!");
    }
    return op;
}

std::string SdbApp::operator()(int argc, const char** argv) {
    Sdb database_;
    std::string operation = "";
    std::ostringstream stream;

    if (argc == 1) {
        return Help(argv[0]);
    } else if (argc == 2) {
        operation = ParseOperation(argv[1]);
        if (operation == "GET_GOOD_STUDENTS") {
            stream << "Number of good students: "
            << database_.GetNumberOfGoodStudents() << std::endl;
        } else if (operation == "GET_BAD_STUDENTS") {
            stream << "Number of bad students: "
            << database_.GetNumberOfBadStudents() << std::endl;
        } else if (operation == "GET_NUMBER_STUDENTS") {
            stream << "Number of students: "
            << database_.GetNumberOfStudents() << std::endl;
        } else {
            throw "Number of arguments and operation is incompatible";
        }
    } else if (argc == 3) {
        operation = ParseOperation(argv[1]);
        if (operation == "GET_AVG_MARK") {
            float mark = database_.GetAvgMark(argv[2]);
            stream << "Average mark: " << mark
                   << std::endl;
        } else if (operation == "REMOVE_STUDENT") {
            database_.RemoveStudent(argv[2]);
                stream << "Student " << argv[2] << " removed"
                       << std::endl;
        } else {
            throw "Number of arguments and operation is incompatible";
        }
    } else if (argc == 4) {
        operation = ParseOperation(argv[1]);
        if (operation == "ADD_STUDENT") {
           stream << "Student " << argv[3] << " added";
        } else {
            throw "Number of arguments and operation is incompatible";
        }
    } else if (argc == 5) {
        operation = ParseOperation(argv[1]);
        if (operation == "ADD_MARK") {
            char* pEnd;
            database_.AddMark(argv[2], argv[3],
                    std::strtol(argv[4], &pEnd, 10));
                stream << "Mark " << argv[4] << " was added to "
                << argv[2] << std::endl;
        } else {
            throw "Number of arguments and operation is incompatible";
        }
    } else {
        throw "Number of arguments is invalid";
    }

    message_ = stream.str();

    return message_;
}

