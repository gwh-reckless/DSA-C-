#pragma once

#include "Vector.h"

template <typename T>
int Vector<T>::uniquify(){
  int i = 0; 
  int j = 1;
  int oldSize = _size;
  while(j < _size){
    if(_elem[j] != _elem[i]) _elem[++i] = _elem[j++];
    else j++;
  }
  _size = ++i;
  return _size - oldSize;
}

