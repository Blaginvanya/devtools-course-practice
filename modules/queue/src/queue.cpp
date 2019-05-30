// Copyright 2019 Gribanov Mihail

#include "include/queue.h"

Queue::Queue(int s) {
    if (s < 1)
        throw "Queue size < 1";
    tail_ = -1;
    head_ = -1;
    pq_.resize(s);
    size_ = s;
    count_ = 0;
}

Queue::Queue(const Queue &q) {
    tail_ = q.tail_;
    head_ = q.head_;
    size_ = q.size_;
    count_ = q.count_;
    pq_ = q.pq_;
}

void Queue::Put(int val) {
    if (count_ == size_)
        throw "No space";
    tail_ = GetNextIndex(tail_);
    pq_.at(tail_) = val;
    count_++;
}

int Queue::Get() {
    if (count_ == 0)
        throw "Queue is empty";
    head_ = GetNextIndex(head_);
    count_--;
    return pq_[head_];
}

int Queue::TopElem() const {
    if (count_ == 0)
        throw "Queue is empty";
    int tempInd = GetNextIndex(head_);
    return pq_[tempInd];
}

int Queue::GetCount() const {
    return count_;
}

int Queue::GetNextIndex(int index) const {
    if (index == size_ - 1)
        return 0;
    return ++index;
}
