#pragma once

#include "BinTree.h"
#include "_share/release.h"

template <typename T>
int BinTree<T>::remove(BinNodePosi<T> x){
  FromParentTo(*x) = nullptr;
  updateHeightAbove(x->parent);
  int n = removeAt(x); _size -= n; return n;
}

template <typename T>
int removeAt(BinNodePosi<T> x){
  if(!x) return 0;
  int n = 1 + removeAt(x->lc) + removeAt(x->rc);
  release(x->data); release(x); return n;
}
