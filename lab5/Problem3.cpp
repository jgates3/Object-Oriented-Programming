//: C15:AddingVirtuals.cpp
// Adding virtuals in derivation
#include <iostream>
#include <string>
using namespace std;

class Pet{

  string pname;

public:
// make all the member functions of Pet pure virtual, but provide a definition for name()
  Pet(const string &petName) : pname(petName) {

  }

  virtual string name() { 
    return pname; //didnt alter name()
  } // removed const

  virtual string speak() = 0; //removed  const and return "" with 0.

};

class Dog : public Pet{

  string name;

public:
  Dog(const string &petName) : Pet(petName) {}
  // New virtual function in the Dog class:
  virtual string sit(){ // removed const
    return Pet::name() + " sits"; //pet name sits
  }

  string speak(){ // removed const
    return Pet::name() + " says 'Bark!'"; //pet name speaks 
  }
};

int main(){

  Pet *p = new Dog("Ben"); //leads to Ben barks

  cout << "p[0]->speak() = " << p->speak() << endl; 

  delete p;


  return 0;
} 
