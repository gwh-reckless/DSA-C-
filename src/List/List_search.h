#pragma once

#include "List.h"

template <typename T>
ListNodePosi<T> List<T>::search(T const& e, int n, ListNodePosi<T> p) const{

  p = p ->pred; 
  while( (0 < n) && (e < p->data) ){  
    p = p ->pred; n--;
  }
  return p; // when search fail, return the left bounds' pred (may be header)
}

