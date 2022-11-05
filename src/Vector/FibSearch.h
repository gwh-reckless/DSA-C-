#pragma once

#include "Fib/Fib.h"

using Rank=int;

template <typename T>
Rank fibSearch(T* S, T const& e, Rank lo, Rank hi){
  fibSearch_v1(S, e, lo, hi);
}

template <typename T>
Rank fibSearch_v1(T* S, T const& e, Rank lo, Rank hi){ // satisfy the semantics
  for(Fib fib(hi -lo); lo < hi;){
    while(hi - lo < fib.get()) fib.prev();
    Rank mi = lo + fib.get() - 1;
    (e < S[mi]) ? hi = mi : lo = mi + 1;
  }

  return --lo;
}

template <typename T>
Rank fibSearch_v2(T* S, T const& e, Rank lo, Rank hi){ // does not satisfy the semantics
  for(Fib fib(hi - lo); lo < hi; ){
    while(hi -lo < fib.get()) fib.prev();
    Rank mi = lo + fib.get() - 1;
    if (e < S[mi]) hi = mi;
    else if (S[mi] < e) lo = mi + 1;
    else return mi;
  }
  return -1;
}
