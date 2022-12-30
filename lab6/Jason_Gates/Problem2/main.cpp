#include <iostream>
#include <string>
#include "myHeader2.h"
using namespace std;

void test1(){

    myNamespace::func1(); // calls to functions using global resolution operator
    myNamespace::func2();
}

void test2(){

    using namespace myNamespace2; // without this functions will be undefined
    func3();                      // called with directive to your namespace (line above important)
    func4();

}

int main(){

    test1(); //function calls
    test2();
    return 0;

}