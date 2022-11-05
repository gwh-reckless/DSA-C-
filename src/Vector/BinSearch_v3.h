#pragma once

using Rank=int;

template <typename T> Rank BinSearch_v3(const T* S, T const& e, Rank lo, Rank hi){
  while(lo < hi){
    Rank mi = (lo + hi) >> 1;
    (e < S[mi]) ? hi = mi : lo = mi + 1;
  }
  return lo -1;
}
