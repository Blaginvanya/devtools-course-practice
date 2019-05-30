// Copyright 2019 Gribanov Mihail

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <iostream>
#include <vector>

class Queue {
 private:
    int tail_;
    int head_;
    std::vector<int> pq_;
    int size_;
    int count_;

    int GetNextIndex(int index) const;

 public:
    explicit Queue(int s = 10);
    Queue(const Queue &q);

    void Put(int val);
    int Get();
    int TopElem() const;
    int GetCount() const;
};
#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
