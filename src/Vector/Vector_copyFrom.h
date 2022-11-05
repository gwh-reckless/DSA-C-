#pragma once
#include "Vector.h"

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi){
  if(_elem) delete _elem;
  _elem = new T[_capacity = max(2*(hi - lo),DEFAULT_CAPACITY)];
  for(_size = 0; lo < hi; lo++,_size++){
    _elem[_size] = A[lo]; 
  }
}
