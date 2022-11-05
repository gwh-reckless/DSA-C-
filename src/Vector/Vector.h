#pragma once

#define DEFAULT_CAPACITY 3
using Rank=int;
template <typename T>
class Vector {
protected:
  T* _elem; Rank _size; Rank _capacity;
  void copyFrom(T const* A, Rank lo, Rank hi);
public:
  Vector(int c = DEFAULT_CAPACITY, Rank s = 0, T v = 0)
  { _elem = new T[_capacity=c]; for(_size = 0; _size  < s; _elem[_size++] = v); }
  Vector(T const* A, Rank n) {copyfrom(A,0, n);}
  Vector(T const* A, Rank lo, Rank hi) {copyFrom(A, lo, hi);}
  Vector(Vector<T> const& V) {copyFrom(V._elem, 0, V._size);}
  Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi);}
  
  // static
  Rank size() const { return _size; }
  bool empty() const { return !_size; }
  Rank find(T const& e);
  Rank find(T const& e, Rank lo, Rank hi);
  Rank search(T const& e);
  Rank search(T const& e, Rank lo, Rank hi);

  // dynamic
  T remove(Rank r) { T v = _elem[r]; remove(r, r+1);  return v;}
  int remove(Rank lo, Rank hi);
  Rank insert(T const& e){ insert(_size, e);} // insert at the bottom
  Rank insert(Rank r, T const& e);
  void sort() { sort(0,_size);}
  void sort(Rank lo, Rank hi);
  void unsort(){ unsort(0,_size);}
  void unsort(Rank lo, Rank hi);
  Rank deduplicate();
  Rank uniquify();

  void traverse(void(*)(T& ));
  template <typename VST> void traverse(VST& );
};

#include "Vector_implementations.h"
