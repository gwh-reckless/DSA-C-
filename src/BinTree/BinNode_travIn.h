#pragma once

#include "BinNode.h"
#include "Stack/Stack.h"

template<typename T>
template <typename VST> void BinNode<T>::travIn(VST& visit){
  
}

template <typename T, typename VST> void goAlongTheVine(BinNodePosi<T>& x, Stack<BinNodePosi<T>> S ){
  while(x){
    S.push(x); x =  x->lc;
  }
}

template <typename T, typename VST> void travIn_I1(BinNodePosi<T> x, VST& visit){
  Stack<BinNodePosi<T>> S;
  while(true){
    goAlongTheVine(x);
    if(S.empty()) break;
    x = S.pop();
    visit(x);
    if(HasRChild(*x)) x = x->rc;
  }
}

template <typename T, typename VST> void travIn_I2(BinNodePosi<T> x, VST& visit){
  Stack<BinNodePosi<T>> S;
  while(true){
    if(x) {
      S.push(x);
      x = x->left;
    } else if( !S.empty()){
      x = S.pop();
      visit(x);
      x = x->rc; // if no right child, x will be null, so keep pop
    } else {
      break;
    }
  }
}


// Version 4: No Need for Stack , Need a backtrac flag 
template <typename T, typename VST> void travIn_I3(BinNodePosi<T> x, VST& visit){ 
  bool backtrack = false;
  while(true){
    if(!backtrack & HasLChild(*x)){
      x = x->lc;
    } else {
      visit(x->data);
      if(HasRChild(*x)) {
        x = x ->rc;
        backtrack = false;
      } else {
        if(!(x=x->succ())) break;
        backtrack = true;
      }
    }
  } 
}

// No need for Stack, No need for backtrac  flag
template <typename T, typename VST> void travIn_I4(BinNodePosi<T> x, VST& visit){
  while(true){
    if(HasLChild(*x)){ // go along the left 
      x = x ->lc;
    } else { // when we can't go left anymore
      visit(x);  // visit x
      while(!HasRChild(*x)){ // while x doesn't have right child
        if(!(x = x->succ())) return; // get back x = x ->succ()
        else visit(x->data); // visit x 
      }
      x = x->rc;  // shift control to right child
    }
  }
}
