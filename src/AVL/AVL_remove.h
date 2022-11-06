#pragma once

#include "AVL.h"

template <typename T>
bool AVL<T>::remove(const T& e){
  BinNodePosi<T>& x = search(e); if(!x) return false; // _hot is the parent of the deleted node
  removeAt(x,this->_hot); this->_size--;
  for(BinNodePosi<T> g = this->_hot; g; g = g->parent){
    if(!AvlBalanced(*g))
      g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
    updateHeight(g);
  }
  return true;
}

