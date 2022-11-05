#pragma once
#include "Vector.h"
#include "BinSearch_v1.h"
#include "BinSearch_v2.h"
#include "BinSearch_v3.h"

using Rank=int;

template <typename T>
Rank BinSearch(const T* _elem, const T& e, Rank lo, Rank hi){
  //return BinSearch_v1(_elem, e, lo, hi);
  //return BinSearch_v2(_elem, e, lo, hi);
  return BinSearch_v3(_elem, e, lo, hi);
}
