#pragma once

#include "List.h"

template <typename T>
int List<T>::uniquify(){
  int oldSize = _size;
  ListNodePosi<T> p = first(); ListNodePosi<T> q;
  while(trailer != (q = p -> succ)){
    if(p->data != q->data)  p = q;
    else remove(q);
  }
  return oldSize - _size;
}
