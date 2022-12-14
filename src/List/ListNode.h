#pragma once

using Rank=int;

template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*;

template <typename T> struct ListNode{
  T data; ListNodePosi<T> pred; ListNode<T> succ;
  ListNode(){}
  ListNode(T e, ListNodePosi<T> p = nullptr, ListNodePosi<T> s = nullptr)
    : data(e), pred(p), succ(s){}

  ListNodePosi<T> insertAsPred(T const& e);
  ListNodePosi<T> insertAsSucc(T const & e);
};

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsPred(T const& e){
  ListNodePosi<T> x = new ListNode(e, pred, this);
  pred->succ = x; pred = x;
  return pred;
}

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsSucc(T const& e){
  ListNodePosi<T> x = new ListNode(e, this, succ);
  succ->pred = x; succ = x;
  return succ;
}
