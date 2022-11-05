#pragma once

using Rank=int;

class Fib{
private:
  Rank f, g; // f = fib(k-1), g = fib(k)
public:
  Fib(Rank n){
    f = 0; g = 1; while(g < n) next();
  }
  Rank get() { return g; }
  Rank next() { g += f; f = g -f; return g;}
  Rank prev() { f = g - f; g -= f; return g; }
};
