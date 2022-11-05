#pragma once

#include "Vector.h"

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi){
  if( lo == hi) return 0;   // for efficiency ?
  while(hi < _size) _elem[lo++] = _elem[hi++];
  _size = lo;  
  return  hi - lo;
}
