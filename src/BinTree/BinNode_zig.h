#pragma once
#include "BinNode.h"
template <typename T>
BinNodePosi<T> BinNode<T>::zig(){
  BinNodePosi<T> lChild = lc;
  lChild->parent = this->parent;
  if(lChild->parent){
    (IsLChild(*this) ? lChild->parent->rc : lChild->parnet->lc) = lChild;
  }
  lc = lChild->rc; if(lc) lc->parent = this;
  lChild->rc = this; this->parent = lChild;

  // update heightes 
  height = 1 + max(stature(lc), stature(rc));
  lChild->height = 1 + max(stature(lChild->lc), stature(lChild->rc));
  for(BinNodePosi<T> x = lChild->parent; x; x = x->parent){
    if(HeightUpated(*x)){
      break;
    } else {
      x -> height = 1 + max(stature(x->lc), stature(x->rc)); 
    }
  }
  return lChild;
}


