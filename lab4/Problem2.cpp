#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int **Func1(int **& x){ //argument of a reference to a pointer to a pointer
    int y = 900;
    *x = &y; //updates pointer x with address of y and makes it 900
    return *&x; //returns
}

int main(){
    int x = 10;
    int* xpointer = &x; //gets address of x
    int**z; //pointer intialization
    int** xpointer2 = &xpointer; 
    cout<<*(*xpointer2)<<endl; //original value of x
    z = Func1(xpointer2); //function call to change value for pointer
    cout<<*(*z)<<endl; //*(*z) is equivalent to *(*xpointer2) but changed variable for function return. You can still see the change regardless of variable names

    return 0;
}