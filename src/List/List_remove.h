#pragma once

#include "List.h"
template <typename T> T List<T>::remove(ListNodePosi<T> p){
  T e = p->date;
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p; _size--;
  return e;
}
