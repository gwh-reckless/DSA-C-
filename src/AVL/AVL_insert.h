#pragma once
#include "AVL.h"

template <typename T> BinNodePosi<T> AVL<T>::insert(const T& e){
  BinNodePosi<T>&x = search(e); if(x) return x;
  BinNodePosi<T> xx = x = new BinNode<T>(e, this->_hot); this->_size++;

  // if x's parent _hot's height increased, then the grandapa may increased
  for(BinNodePosi<T> g = this->_hot; g; g=g->parent){
    if(!AvlBalanced(*g)) {
      FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g))); // taller taller child gives us v
    } else {
      this->updateHeight(g);
    }
  }
  return xx;
}
