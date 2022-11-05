
/***
Check for BinNode's status and propreties
***/
#include <string>
#define IsRoot(x) ( !(x).parent )
#define IsLChild(x) ( !IsRoot(x) && (&(x) == (x).parent->lc) )
#define IsRChild(x) ( !IsRoot(x) && (&(x) == (x).parent->rc) )
#define HasParent(x) ( !IsRoot(x) )
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) &&  HasRChild(x) )
#define IsLeaf(x) ( !HasChild(x) )


/***
get other node(pointer) by relationship
***/
#define sibling(p) ( IsLChild(*(p)) ? (p)->parent-rc : (p)->parent->lc)
#define uncle(x) (sibling((x)->parent))
#define FromParentTo(x) /* if x is root node, we return _root of the tree */\
  (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc)) 
