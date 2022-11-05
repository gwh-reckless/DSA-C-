#pragma once

#define  stature(p) ((p) ? (p) -> height : -1)

template <typename T> struct BinNode;
template <typename T> using BinNodePosi=BinNode<T>*;


template <typename T>
struct BinNode {
  T data;
  BinNodePosi<T> parent, lc, rc;
  int height;


  
  BinNode():
    parent(nullptr), lc(nullptr), rc(nullptr), height(0) {}

  BinNode(T e, BinNodePosi<T> parent=nullptr, BinNodePosi<T> lc=nullptr, BinNodePosi<T> rc=nullptr)
  : data(e), parent(parent), lc(lc), rc(rc) {}

  // Static
  int size(); // get the nodes count of the tree with this as root
  BinNodePosi<T> insertAsLC(T const & );
  BinNodePosi<T> insertAsRC(T const & );
  BinNodePosi<T> succ(); // the next one in  In-Order traverse
  
  // traverse
  template <typename VST> void travLevel(VST&);
  template <typename VST> void travPre(VST&);
  template <typename VST> void travIn(VST&);
  template <typename VST> void travPost(VST&);
  template <typename VST> void traverse(VST&);

  // operator
  bool operator<(BinNode const& bn) { return data < bn.data; }
  bool operator==(BinNode const& bn) { return data == bn.data; }

  BinNodePosi<T> zig();
  BinNodePosi<T> zag();
  BinNodePosi<T> balance();
};




