#pragma once

#include "Vector.h"


template <typename T>
Rank  Vector<T>::deduplicate(){
  int i = 1; 
  int j = 1;
  while(j < _size){
    if(!find(_elem[j], 0, i)) _elem[i++] = _elem[j++];
    else  j++;
  }
  _size = i;
  return j - i;
}
