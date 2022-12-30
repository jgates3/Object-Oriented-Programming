#include <iostream> 
using namespace std; 

char* charFunction(char*input){ //char* charFunction to handle pointers
    int length =0; //length initialization
  
    for (int i =0; *(input+i)!='\0'; i++){ //null terminator. loops to end of the input and stops when a null value is found
        length = i; //keeps track of input length

}
    length = length +1; //length was a bit off so this corrects it to find the correct length
    char*arr = new char[length]; //dynamically allocates an array of char that is the size of the char array thats passed to the function
    for (int i = 0; i <length; i++){
        *(arr +i) = *(input + i); //copies characters (can also be written as arrays instead of pointers)

}
    return arr; //returns copy
}

int main(){
    char* output;  
    char* output2;
    char tester[] = "This a test string. Testing 1 2 3..."; //input
    output = charFunction(tester); //calls to functions
    output2 = charFunction(output);
    cout<<"This is first output or first string: " <<(output) << "\n";
    cout<<"This is second output or second string: " <<(output2) << "\n";
    cout<<"Here is the pointer for the first output: "<< &output<< "\n";
    cout<<"Here is the pointer for the second output: "<< &output2<< "\n";
    //both strings print out and are the same, but have different storage. 
    delete[] output; //cleans up dynamic storage
    delete [] output2;

    return 0;
}