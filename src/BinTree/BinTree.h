#pragma once

#include "BinNode.h"
template <typename T> class BinTree {
protected:
  int _size; BinNodePosi<T> _root;
  virtual int updateHeight(BinNodePosi<T> x);
  void updateHeightAbove(BinNodePosi<T> x);
public:
  BinTree() : _size(0), _root(NULL) {}
  ~BinTree() {if(0 < _size) remove(_root);}

  // static
  int size() const { return _size; }
  bool empty() const { return !_root; }
  BinNodePosi<T> root() const { return _root; }
  
  // dynamic
  BinNodePosi<T> insert(T const &); // insert root node
  BinNodePosi<T> insert(T const & , BinNodePosi<T> ); // insert left child
  BinNodePosi<T> insert(BinNodePosi<T>, T const &); // insert right child
  BinNodePosi<T> attach(BinTree<T>*&, BinNodePosi<T>); // attach left sub tree
  BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T>*&); // attach right sub tree
  int remove(BinNodePosi<T>); // remove sub tree
  BinTree<T>* secede(BinNodePosi<T>); // ????

  // traverse
  template <typename VST>
  void traveLevel(VST& visit) { if(_root) _root->traveLevel(visit);}
  template <typename VST>
  void travPre(VST& visit) { if(_root) _root->travPre(visit);}
  template <typename VST>
  void travIn(VST& visit) { if(_root) _root->travIn(visit);}
  template <typename VST>
  void travPost(VST& visit) { if(_root) _root->travPost(visit);}
  template <typename VST>
  void traverse(VST&);

  // operator
  bool operator<(BinTree<T> const& t)
  { return _root && t._root && lt(_root, t._root);}
  bool operator==(BinTree<T> const& t)
  { return _root && t._root && (_root == t._root);}
};

#include  "BinTree_implementations.h"

