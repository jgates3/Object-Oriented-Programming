#include <iostream>
#include <string>
using namespace std;

class mySimpleClass{

    int x;
    
public:
    mySimpleClass(int i = 0){ // esentially a initializer list (needed for specific numbers (a(2)) for main )
        x = i;
    }

    mySimpleClass operator+(mySimpleClass obj) const {                              // member functions being overloaded
        mySimpleClass addoutput;  //+ represents adding two things together (also direct member selection via object name )
        addoutput = x + obj.x;
        return addoutput;
    }

    mySimpleClass operator*(mySimpleClass obj) const {
        mySimpleClass multioutput; //initialization/giving it a variable
        multioutput = x * obj.x; //* represents multiplying two things together (also direct member selection via object name )
        return multioutput;
    }

    void print(ostream &out){ // takes an ostream& out and prints it
        out << x << endl; // prints x (a numeric value)
    }
};

int main(){

    mySimpleClass a(2); // initializer list helps us make a essentially be 2  (change a and b numbers to test )
    mySimpleClass b(5); // initializer list helps us make b essentially be 5
    mySimpleClass c(0);  // doesnt matter what value it is since its being overwritten.
    c = (a * a) + (b * b); 
    a.print(cout); // prints a (line used for testing and correctness)
    b.print(cout); // prints b (line used for testing and correctness)
    c.print(cout); // line prints c

    return 0;
}