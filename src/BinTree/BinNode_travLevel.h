#pragma once
#include "BinNode.h"
#include "Queue/queue.h"

template <typename T>
template <typename VST> void BinNode<T>::travLevel(VST& visit){
  Queue<BinNodePosi<T>> Q;
  Q.enqueue(this);
  while(!Q.empty()){
    BinNodePosi<T> x = Q.dequeue();
    visit(x->data);
    if(HasLChild(*this)) Q.enqueue(x->lc);
    if(HasRChild(*this)) Q.enqueue(x->rc);
  }
}
