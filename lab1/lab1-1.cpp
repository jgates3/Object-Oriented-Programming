#define _USE_MATH_DEFINES //used for precise pi
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float n;  //variable for user input
    float aoc; //area of the circle variable
    cout<<"Enter the radius of the circle:"; //print
        cin>>n;  //gets user input
        aoc = M_PI * pow(n,2); //calculates the area of circle (pi*r^2)
    cout<<"The area of the circle is: "<<aoc; //prints area of circle
}