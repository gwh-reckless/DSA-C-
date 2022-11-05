#pragma once

#include "Vector.h"
#include "mergeSort.h"

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi){
  mergeSort(_elem,lo, hi); 
}

