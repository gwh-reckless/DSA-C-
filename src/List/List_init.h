#pragma once

#include "List.h"
template <typename T>
void  List<T>::init()
{
  _size = 0;
  header = new ListNode<T>();
  trailer = new ListNode<T>();
  header -> succ = trailer;
  trailer -> pred = header;
}
