#pragma once

#include "ListNode.h"

template <typename T> class List {
private:
  int _size; ListNodePosi<T> header, trailer;

protected:
  void init();
  int clear();
  void copyNodes(ListNodePosi<T>, int);

public:
  List(){ init(); }
  List(List<T> const& L); // copy from List L
  List(List<T> const& L, Rank r, int n); 
  List(ListNodePosi<T> p, int n);
  ~List();

  // static
  Rank size() const { return _size;}
  bool empty() const { return _size <= 0; }
  ListNodePosi<T> first() const { return header->succ; }
  ListNodePosi<T> last() const { return trailer->pred; }
  bool valid(ListNodePosi<T> p) { return p && (trailer != p) && (header != p);}
  ListNodePosi<T> find(T const& e) const { return find(e, _size, trailer);} 
  ListNodePosi<T> find(T const& e, int n, ListNodePosi<T> p) const; // find [p-n, p)
  ListNodePosi<T> search(T const& e) const { return search(e, _size, trailer); }  
  ListNodePosi<T> search(T const& e, int n, ListNodePosi<T> p) const; // search [p -n, p)

  // dynamic
  ListNodePosi<T> insertAsFirst(T const& e);
  ListNodePosi<T> insertAsLast(T const& e);
  ListNodePosi<T> insert(ListNodePosi<T> p, T const& e);
  ListNodePosi<T> insert(T const& e, ListNodePosi<T> p);
  T remove(ListNodePosi<T> p); // return the deleted node's data
  void sort(ListNodePosi<T> p, int n);
  void sort() {sort(first(), _size);}
  int deduplicate();
  int uniquify();
  void reverse();

  // traverse
  void traverse(void(*)(T&));
  template <typename VST>
  void traverse(VST&);
}; 

#include "List_implementations.h"
