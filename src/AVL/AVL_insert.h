#pragma once
#include "AVL.h"

template <typename T> BinNodePosi<T> AVL<T>::insert(const T& e){
  BinNodePosi<T>&x = search(e); if(x) return x;
  BinNodePosi<T> xx = x = new BinNode<T>(e, this->_hot); this->_size++;

  // if x's parent _hot's height increased, then the grandapa may increased
  for(BinNodePosi<T> g = this->_hot; g; g=g->parent){
    if(!AvlBalanced(*g)) {
      FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g))); // taller taller child gives us v
      break; // when local subtree rebalanced, the height will be recovered, so the parent wouldn't be affected
    } else {
      this->updateHeight(g); // need to update height (note: even g is still balanced, the height still could increase)
    }
  }
  return xx;
}
