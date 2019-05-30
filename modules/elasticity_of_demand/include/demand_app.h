// Copyright 2019 Yakovlev Pavel

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_DEMAND_APP_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_DEMAND_APP_H_

#include <string>
#include "include/elasticity_of_demand.h"

class DemandApp {
 public:
    DemandApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    enum {
        PRICE_DEMAND = 1,
        INCOME_DEMAND = 2,
        CROSS_DEMAND = 3
    };
    typedef struct {
        double price1, price2;
        int quantity1, quantity2;
        double income1, income2;
        char operation;
    } Arguments;
};

#endif  // MODULES_ELASTICITY_OF_DEMAND_INCLUDE_DEMAND_APP_H_
