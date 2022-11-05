#pragma once

#include "Vector/Vector.h"

template <typename T> class Stack: public Vector<T> {
public:
  void push(T const& e) { insert(e);}
  T pop() { return remove(this->size() -1);}
  T top() { return (*this)[this->size() -1];}
};
