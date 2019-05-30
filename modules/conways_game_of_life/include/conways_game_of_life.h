// Copyright 2019 Logvinenko Alexandra
#pragma once
#ifndef MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
#define MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_

#include <vector>

class Conways_life {
 private:
    int sizeh_, sizew_;
    std::vector<char> field_;
    std::vector<bool> check_;

    void checkNextStep();
    void redraw();

 public:
    Conways_life(const int w, const int h);
    int getW();
    int getH();
    char getPoint(const int wi, const int hi);
    void putStart(const int wi, const int hi);

    int countNeighbors(const int wi, const int hi);
    void stepNextField();
    bool isSystemAlive();
    bool aliveNextStep(const int wi, const int hi);

    void Start();
};

#endif  // MODULES_CONWAYS_GAME_OF_LIFE_INCLUDE_CONWAYS_GAME_OF_LIFE_H_
