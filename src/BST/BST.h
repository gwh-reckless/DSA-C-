#pragma once

#include "BinTree/BinTree.h"

template <typename T> class BST : public BinTree<T> {
protected:
  BinNodePosi<T> _hot; // the hit node's parent
  BinNodePosi<T> connect34 (
    BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
    BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>
  );
  BinNodePosi<T> rotateAt(BinNodePosi<T> x);
public:
  virtual BinNodePosi<T>& search( const T& e);
  virtual BinNodePosi<T> insert(const T& e);
  virtual bool remove(const T& e);
};

#include "BST_implementations.h"
