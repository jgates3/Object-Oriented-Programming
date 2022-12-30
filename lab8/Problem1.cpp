#include <iostream>
using namespace std;

template <typename T> //creates/allows us to use templates
T fibonacci(T counter){ //templatizes (make us able to use any type)

  static T num1 = 0; //static T variables 
  static T num2 = 1; //start with 0 and 1
  static T sum = 0; //sum of num1 and num2
  T newCounter;  

  cout << sum << " "; //prints out fib numbers

  if (counter > 0){ //recursive fib if it is bigger than 0 
    sum = num1 + num2; //sum of num1 and num2
    num1 = num2; //num2 value is in num1
    num2 = sum; //num2 contains the sum
    newCounter = counter - 1; //used to find the correct fib numbers (without -1 will lead to incorrect numbers)
    fibonacci(newCounter); //call to itself
  }

  return 0;

}

int main(){

  cout << "Integer values: "<<endl; //integers
  fibonacci<int>(10); //change number to test out fib
  cout << endl;

  cout << "Float values: "<<endl; //float
  fibonacci<float>(10);
  cout << endl;

  cout << "Long values: "<<endl; //long
  fibonacci<long>(90);
  cout << endl;

  cout << "Double values: "<<endl; //double
  fibonacci<double>(10);
  cout << endl;

  return 0;
}