#pragma once
#include "_share/util.h"

#define HeightUpated(x) \
  ( (x).height == 1 + max( stature((x).lc) , stature((x)->rc)) )

#define Balanced(x) (stature((x).lc) == stature((x).rc)) // The ideal balance condition
#define BalFac(x) (stature((x).lc) - stature((x).rc)) // Balance Factor
#define AvlBalanced(x) ( (-2 < BalFac(x)) && (BalFac(x) < 2)) // AVL Blanced condition


