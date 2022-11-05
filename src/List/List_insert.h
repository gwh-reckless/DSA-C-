#pragma once
#include "List.h"

template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(T const& e){
  return header->insertAsSucc(e);
}
template <typename T>
ListNodePosi<T> List<T>::insertAsLast(T const& e){
  return header->insertAsPred(e);
}
template <typename T>
ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const& e){
  _size++;
  return p->insertAsSucc(e);
}
template <typename T>
ListNodePosi<T> List<T>::insert(T const& e, ListNodePosi<T> p){
  _size++;
  return p->insertAsPred(e);
}


