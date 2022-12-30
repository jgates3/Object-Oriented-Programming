#include "lab1-2.h" //essential for the program and needed in order to read the contents of the .h file
#include <iostream>
using namespace std;
//compile using  g++ lab1-20.cpp lab1-2.cpp -o ./a.out
//each function prints a unique statement to show that each function is working properly
//each function also prints out the function name, argument list and return type. Each function also returns the value.
void voidFunction(void){ 
    cout<<"This function is voidFunction and its argument is void. The return type is also void. \n";
        return;
}
char charFunction(char i){
    cout<<"This function is charFunction and its argument is char i. When function calls are used the argument specifically becomes char: " <<i << " The return type is also char. \n";
        return i;
}
int intFunction(int i){
    cout<<"This function is intFunction and its argument is int i. When function calls are used the argument specifically becomes int: " << i << " The return type is also int. \n";
        return i;
}
float floatFunction(float i){
    cout<<"This function is floatFunction and its argument is float i. When function calls are used the argument specifically becomes float: " << i << " The return type is also float. \n";
        return i;
}
