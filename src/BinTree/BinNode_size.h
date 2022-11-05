#pragma once

#include "BinNode.h"

template <typename T> int BinNode<T>::size(){
  int count = 1;
  if(lc) count += lc->size();
  if(rc) count += rc->size();
  return count;
}
