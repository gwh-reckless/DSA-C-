#pragma once

#include "List.h"

template <typename T> int List<T>::deduplicate(){
  int oldSize = _size; ListNodePosi<T> p = first();
  for(Rank r = 0; p != trailer; p = p -> succ()){
    if(ListNodePosi<T> q = find(p->data, r, p)){
      remove(q);
    } else r++;
  }

  return oldSize - _size;
}
