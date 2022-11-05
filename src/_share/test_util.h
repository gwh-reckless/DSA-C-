#pragma once
#include <iostream>
#define Log(x) std::cout<<x<<"--";

template <typename T>
class Print{
  void operator()(T& e){
    Log(e);
  }
};

template <typename T>
void print(T&e){
  Log(e); 
}
