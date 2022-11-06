#pragma once
#include "BST.h"

template <typename T> bool BST<T>::remove(const T& e){
  BinNodePosi<T>& x = search(e); if(!x) return false;
  removeAt(x, _hot); this->_size--;
  this->updateHeightAbove(_hot);
  return true;
}

template <typename T>
BinNodePosi<T> removeAt(BinNodePosi<T>& x, BinNodePosi<T>& hot){
  // note : x is _hot->lc | _hot->rc
  BinNodePosi<T> w = x; // w will be a name for the actual deleted node
  BinNodePosi<T> succ = nullptr; // succ is the whose parent need to change
  if(!HasLChild(*x))
    succ = x = x ->rc; // x(_hot -> lc|rc) = x ->rc   : downlink
  else if (!HasRChild(*x))
    succ = x = x ->lc;
  else{
    w = w->succ();  
    swap(x->data, w->data);
    BinNodePosi<T> u = w->parent;
    ((u == x) ? u->rc:u->lc) = succ = w->rc; // downlink
  }
  hot = w->parent; // hot now is the parent of deleted node
  if(succ) succ->parnet = hot; // up link
  release(w->data); release(w); return succ;
}
