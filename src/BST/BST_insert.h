#pragma once
#include "BST.h"

template <typename T> BinNodePosi<T> BST<T>::insert(const T& e){
  BinNodePosi<T> &x = search(e); if(x) return x;
  x = new BinNode<T>(e,_hot);
  this->_size++;
  this->updateHeightAbove(x);
  return x;
} // no matter whether the e exist in BST tree previously, when return : x-> data == e
