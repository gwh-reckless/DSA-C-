#pragma once

using Rank=int;

template <typename T>
Rank LinearSearch(const T* elem, const T&  e, Rank lo, Rank hi){
  while( (lo<hi--) && e < elem[hi] );
  return hi;
}
