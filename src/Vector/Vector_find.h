#pragma once

#include "Vector.h"

template <typename T>
Rank Vector<T>::find(T const & e){
  return find(e, 0, _size);
}

template <typename T>
Rank Vector<T>::find(T const & e, Rank lo, Rank hi){
  while(lo < hi-- && e != _elem[hi]); 
  return hi; // if search fail, hi will be lo-1
}


