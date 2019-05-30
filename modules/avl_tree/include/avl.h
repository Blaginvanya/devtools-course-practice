// Copyright 2019 Denis Yakovlev

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_H_
#include <cinttypes>

using key = std::int64_t;

key GetRandomKey(key nBegin, key nEnd);

struct CNode {
    key data_;
    CNode* pLeft_;
    CNode* pRight_;
    int height_;
};
class CAvl {
 private:
    CNode* Insert(const key& x, CNode* t);
    CNode* SingleRightRotate(CNode* t);
    CNode* SingleLeftRotate(CNode* t);
    CNode* DoubleLeftRotate(CNode* t);
    CNode* DoubleRightRotate(CNode* t);
    CNode* FindMin(CNode* t);
    CNode* FindMax(CNode* t);
    CNode* Remove(const key& x, CNode* t);
    int Height(CNode* t);
    CNode* pRoot_;
 public:
    CAvl();
    key Find(const key& x);
    void Insert(const key& x);
    void Remove(const key& x);
    key GetRoot() const;
    key FindMin();
    key FindMax();
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_H_
