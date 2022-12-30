#include <iostream>
#include <string>
using namespace std;

class myClass{ // Creates a class myClass

    float f1;                                         // contains a const
    const float f2;
    
public:
    //float f1;                                         // contains a const (uncomment to test code & print statements since wasnt sure if variables were suppose to be in public or private in the class)
    //const float f2;                                   // contains a non-cost
    myClass(float i, const float j) : f1(i), f2(j) {} // initializer list

};

int main(){

    myClass obj(11.132, 132.2);                  // call to myClass and usage of  initializer list
    //cout << "NonConst Float:" << obj.f1 << endl; // prints nonconst (used to test code by making variables f1 and f2 public)
    //cout << "Const Float:" << obj.f2 << endl;    // prints const (used to test code by making variables f1 and f2 public)
    return 0;
 
}