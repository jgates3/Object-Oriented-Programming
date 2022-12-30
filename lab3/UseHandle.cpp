//: C05:UseHandle.cpp 
//{L} Handle 
// Use the Handle class 
//Run using g++ UseHandle.cpp Handle.cpp -o ./a.out
#include "Handle.h"
int main() { 
  Handle u; 
  //u.initialize(); 
  u.read(); 
  u.change(1); 
  //u.cleanup(); 
} ///:~ 