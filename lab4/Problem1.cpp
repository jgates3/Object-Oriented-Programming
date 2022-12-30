#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
 
int& Func1(int* a) { //has point argument (function modifies what pointer points to)
    int& b = *a;
    b = 700 -*a; //does 700 -21 and changes value
    return b; //returns reference
}

int main() {
//prints out the addresses and variables
    int x = 21;
    cout << x << endl;
    int b = Func1(&x); //call to function 
    cout << b << endl; //print changed value

return 0;
}