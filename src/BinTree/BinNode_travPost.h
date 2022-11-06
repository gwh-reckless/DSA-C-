#pragma once

#include "BinNode.h"
#include "Stack/Stack.h"

template <typename T>
template <typename VST> void BinNode<T>::travPost(VST& visit){
  travPost_I(this,visit);
}


template <typename T> 
void gotoLeftMostLeaf(Stack<BinNodePosi<T>>& S){
  while(BinNodePosi<T> x = S.top()){ // x, RChild, LChild
    if(HasLChild(*x)) {
      if(HasRChild(*x)){
        S.push(x->rc);
      }
      S.push(x->lc);
    } else {
      S.push(x->rc);
    }
  }
  S.pop();
}

template <typename T, typename VST> void travPost_I(BinNodePosi<T> x, VST& visit){
  Stack<BinNodePosi<T>> S;
  if(x) S.push(x);
  while(!S.empty()){
    if(S.top() != x->parent) gotoLeftMostLeaf(S);
    x = S.pop(); visit(x->data);
  }
}
