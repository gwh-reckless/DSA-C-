#pragma once

#include "Vector.h"

template <typename T> void Vector<T>::traverse(void(*visit)(T&)){
  for(Rank i = 0; i < _size; i ++) visit(_elem[i]);
}



template <typename T> template <typename VST>  void Vector<T>::traverse(VST& visit){
  for(Rank i = 0; i < _size; i++) visit(_elem[i]);
}
