#pragma once

#include "BinNode.h"
#include "_share/util.h"

template <typename T>
BinNodePosi<T> BinNode<T>::zag(){
  BinNodePosi<T> rChild =  rc;
  rc->parent = this->parent;
  if(rc->parent){
    (IsLChild(*this) ? rChild->parent->lc : rChild->parent->rc) = rChild;
  }
  rc = rChild -> lc; if(rc) rc->parent = this;
  this->parent = rChild; rChild->lc = this;
  
  // update heights
  this->height = 1 + max(stature(lc), stature(rc));
  rChild -> height = 1 + max(stature(rChild->lc), stature(rChild->rc));
  for(BinNodePosi<T> x = rChild->parent; x; x = x->parent ){
    if(HeightUpated(*x)){
      break;
    } else {
      x->height = 1 + max(stature(x->lc), stature(x->rc));
    }
  }

  return rChild;
}
