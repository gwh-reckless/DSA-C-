#include <iostream>
#include "Vector/Vector.h"
#include "_share/test_util.h"

int main()
{
  Vector<int> V;
  V.insert(0);
  V.insert(1);
  V.insert(1);
  V.insert(2);
  V.insert(0);
  V.insert(3);
  V.insert(3);
  V.deduplicate();
  V.traverse(print);

  return 0;
}
