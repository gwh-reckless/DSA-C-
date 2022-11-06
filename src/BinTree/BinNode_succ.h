#pragma once
#include "BinNode.h"

template <typename T>
BinNodePosi<T> BinNode<T>::succ(){
  BinNodePosi<T> s = this;
  if(rc){ // if s have right child, it goes right
    s = rc;
    while(HasLChild(*s)) s = s->lc; //  while s have left child it goes left
  }  else { // if s doesn't have right child, it goes back
    while(IsRChild(*s)) s = s->parent; // if s it's a Right Child, it keeps going back
    s = s->parent; // now s is a left child, the succ should be its parent
  }
}
