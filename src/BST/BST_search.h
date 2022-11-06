#pragma once

#include "BST.h"


template <typename T>
BinNodePosi<T>& BST<T>::search( const T& e){
  if( !this->_root || e == this->_root->data) { _hot = NULL; return this->_root;} // empty tree or match at _root
  for(_hot = this->_root; ;){
    BinNodePosi<T>& v = ( e < _hot->data) ? _hot->lc : _hot->rc;
    if(!v || e == v->data ) return v;
    _hot = v;
  }
} // note where return a reference _hot->lc | _hot->rc
