// Copyright 2019 Utkin Konstantin

#include <iostream>
#include "include/queue_app.h"

int main(int argc, const char** argv) {
    QueueApplication app;
    std::cout << app(argc, argv);
    return 0;
}
