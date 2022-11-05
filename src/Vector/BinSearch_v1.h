#pragma once

using Rank=int;
template <typename T>
Rank BinSearch_v1(const T *A, T e, Rank lo, Rank hi){
  while(lo < hi){
    int mi = (lo + hi) >> 1;
    if(e < A[mi]){
      hi = mi - 1;
    } else if (A[mi] < e){
      lo = mi + 1;
    }
    if(A[mi] == e) return mi;
  }
  return  -1; // search fail
}

