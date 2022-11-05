#pragma once

using Rank = int;

template <typename T>
Rank  BinSearch_v2(const T* A, const T& e, Rank lo, Rank hi){
  while( 1 <  hi - lo){
    Rank mi  = (lo + hi) >> 1;
    (e<A[mi]) ? hi = mi : lo = mi;
  } // when finish, 1 elements in range,  e <= [one element]
  return e < A[lo] ? lo - 1 :lo;
}

