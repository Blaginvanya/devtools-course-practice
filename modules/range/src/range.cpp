// Copyright 2019 Guseva Catherine

#include "include/range.h"

#include <iostream>
#include <cstring>
#include <string>

Range::Range(std::string str) {
    int size = strlen(str.c_str()) - 1;

    if (str[0] != '[')
        if (str[0] != '(')
            throw std::string("No format");
    if (str[size] != ']')
        if (str[size] != ')')
            throw std::string("No format");

    interval_[1] = 0;
    interval_[2] = 0;

    if (str[0] == '[')
        interval_[0] = 0;
    else
        interval_[0] = 1;

    if (str[size] == ']')
        interval_[3] = 0;
    else
        interval_[3] = 1;

    int c = 0;
    for (int i = 1; i < size; i++) {
        if (c == 0) {
            if (str[i] != ',') {
                interval_[1] = interval_[1] * 10 + (str[i] - '0');
            } else {
                c++;
            }
        } else {
            interval_[2] = interval_[2] * 10 + (str[i] - '0');
        }
    }

    if (interval_[1] >= interval_[2])
        throw std::string("Not format!");

    interval_[1] += interval_[0];
    interval_[2] -= interval_[3];
}

Range::Range(const Range& obj) {
    for (int i = 0; i < 4; i++)
        interval_[i] = obj.interval_[i];
}

bool Range::IntegerRangeContains(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]<interval_[1] || arr[i]>interval_[2])
            return false;
    }

    return true;
}

std::string Range::GetAllPoints() {
    std::string str = "Points: ";
    for (int i = interval_[1]; i <= interval_[2]; i++) {
        str += std::to_string(i);
        if (i != interval_[2])
            str += ", ";
    }
    return str;
}

bool Range::ContainsRange(std::string str) {
    Range tmp(str);

    if (tmp.interval_[1] >= interval_[1] && tmp.interval_[2] <= interval_[2])
        return true;

    return false;
}

std::string Range::EndPoints() {
    std::string str;
    str = "Start: " + std::to_string(interval_[1]) + "\n"
        + "End: " + std::to_string(interval_[2]);

    return str;
}

bool Range::OverlapsRange(std::string str) {
    Range tmp(str);

    if (tmp.interval_[1] > interval_[2] || tmp.interval_[2] < interval_[1])
        return false;

    return true;
}

bool Range::operator==(const Range& obj) const {
    if (obj.interval_[1] != interval_[1] ||
        obj.interval_[2] != interval_[2])
        return false;

    return true;
}

bool Range::operator!=(const Range& obj) const {
    return !(operator==(obj));
}

void Range::SetFirst(int val) {
    interval_[1] = val + interval_[0];

    if (interval_[1] >= interval_[2])
        throw std::string("Not format!");
}

void Range::SetSecond(int val) {
    interval_[2] = val - interval_[3];

    if (interval_[1] >= interval_[2])
        throw std::string("Not format!");
}

int Range::GetFirst() {
    return interval_[1];
}

int Range::GetSecond() {
    return interval_[2];
}
