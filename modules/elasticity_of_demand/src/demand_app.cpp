// Copyright 2019 Yakovlev Pavel

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cstdlib>
#include <string>
#include <sstream>

#include "include/elasticity_of_demand.h"
#include "include/demand_app.h"

enum {
        PRICE_DEMAND = 1,
        INCOME_DEMAND = 2,
        CROSS_DEMAND = 3
    };

DemandApp::DemandApp() : message_("") {}

void DemandApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a elasticity of demand application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <price1> <price2> " +
          "<quantity1> <quantity2>" +
          "<income2> <income2>" +
          " <operation>\n\n" +

          "Where all arguments are double-precision numbers and integers, " +
          "where <operation> :\n" +
          "p - Price Elasticity Of Demand\n" +
          "i - Income Elasticity Of Demand\n" +
          "c - Cross Elasticity Of Demand";
}

bool DemandApp::validateNumberOfArguments(int argc,
                                                    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int ParseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int ParseOperation(const char* arg) {
    int op;
    if (strcmp(arg, "p") == 0) {
        op = PRICE_DEMAND;
    } else if (strcmp(arg, "i") == 0) {
        op = INCOME_DEMAND;
    } else if (strcmp(arg, "c") == 0) {
        op = CROSS_DEMAND;
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string DemandApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.price1    = ParseDouble(argv[1]);
        args.price2    = ParseDouble(argv[2]);
        args.quantity1 = ParseInt(argv[3]);
        args.quantity2 = ParseInt(argv[4]);
        args.income1   = ParseDouble(argv[5]);
        args.income2   = ParseDouble(argv[6]);
        args.operation = ParseOperation(argv[7]);
    }
    catch(std::string& str) {
        return str;
    }

    ElasticityOfDemand obj;

    std::ostringstream stream;
    switch (args.operation) {
     case PRICE_DEMAND:
        stream << "Result = " << obj.PriceElasticityOfDemand(args.quantity1,
            args.quantity2, args.price1, args.price2);
        break;
     case INCOME_DEMAND:
        stream << "Result = " << obj.IncomeElasticityOfDemand(args.quantity1,
            args.quantity2, args.income1, args.income2);
        break;
     case CROSS_DEMAND:
        stream << "Result = " << obj.CrossElasticityOfDemand(args.quantity1,
            args.quantity2, args.price1, args.price2);
        break;
    }

    message_ = stream.str();

    return message_;
}
