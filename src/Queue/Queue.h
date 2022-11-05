#pragma once

#include "List/List.h"

template <typename T> class Queue : public List<T>{
public:
  void enqueue(T const& e) { insertAsLast(e);}
  T dqueue(){ return remove(this->first()); }
  T& front()  { return this->first() -> data;}
};
