#pragma once
#include "BinNode.h"
#include "Stack/Stack.h"

template <typename T>
template <typename VST> void BinNode<T>::travPre(VST& visit){
  travPre_I1(this, visit);
}


template <typename T, typename VST>  void travPre_I1(BinNodePosi<T> x, VST& visit){
  Stack<BinNodePosi<T>> S;
  if(x) S.push(x);
  while(!S.empty()){
    x = S.pop();
    visit(x->data);
    if(HasRChild(*x))  S.push(x->rc);
    if(HasLChild(*x))  S.push(x->lc);
  }
}

template <typename T, typename VST>
void visitAlongTheVine( BinNodePosi<T> x, VST& visit, Stack<BinNodePosi<T>>& S){
  while(x){
    visit(x->data);
    if(HasRChild(*x)) S.push(x->rc);
  }
}
template <typename T, typename VST> void travPre_I2(BinNodePosi<T> x, VST& visit){
  Stack<BinNodePosi<T>> S;
  while(true){
    visitAlongTheVine(x,visit,S);
    if(S.empty()) break;
    x = S.pop();
  } 
}


