#pragma once

#include "List.h"

template <typename T>
ListNodePosi<T> List<T>::find(T const& e, int n, ListNodePosi<T> p) const{ 
  while(0 < n--){
    if( e == ( p = p->pred) -> data) return; 
  }
  return nullptr;
}
