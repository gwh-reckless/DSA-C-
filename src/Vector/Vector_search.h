#pragma once
#include  "Vector.h"

#include "LinearSearch.h"
#include "BinSearch.h"
#include "FibSearch.h"

template <typename T>
Rank Vector<T>::search(T const& e){
  search(e, 0, _size);
}

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi){
  //LinearSearch(_elem, e, lo, hi);
  BinSearch(_elem, e, lo, hi);
  //FibSearch(_elem, e, lo, hi);
}
