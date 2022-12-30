//: C05:Handle.cpp {O} 
// Handle implementation 
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
#include "Handle.h" 
#include "require.h"
struct Handle::Cheshire { 
  int i; 
}; 
 
Handle::Handle() {  //replaced initialize() with constructor since a constructor can be used to initialize
  smile = new Cheshire; 
  smile->i = 0; 
  cout<<"Constructor called!"<<endl; //prints
} 
 
Handle::~Handle() { //replaced cleanup() with destructor since a destructor is known to destroy or delete objects
  delete smile; 
  cout<<"Destructor called!"<<endl; //prints
} 
 
int Handle::read() { 
  return smile->i; 
} 
 
void Handle::change(int x) { 
  smile->i = x; 
} ///:~ 

/*Handle::Handle(){
  cout<<"Constructor called!"<<endl;
}
Handle::~Handle(){
  cout<<"Destructor called!"<<endl;
}
*/