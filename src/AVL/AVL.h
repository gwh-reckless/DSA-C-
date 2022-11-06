#pragma once
#include "BST/BST.h"

template <typename T> class AVL : public BST<T> {
public:
  BinNodePosi<T> insert(const T& e);
  bool remove(const T& e);
};

#include "AVL_implementations.h"

