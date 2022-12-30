#include <iostream>
using namespace std;
class FirstClass
{
public:
    int arr[10] = {1, 2, 37, 50, 12341, 34, 3, 2, 69, 80000};
    int (*pointerarray)[10] = &arr;      // used in order to be printed and iterated through in main
    int len = sizeof(arr) / sizeof(int); // length
};

int main()
{
    FirstClass x; // object to class(FirstClass)
    for (int i = 0; i < x.len; i++)
    {
        // cout<<(&(x.pointerarray) + i)<<endl; this finds the address which is not what we need
        cout << *(*(x.pointerarray) + i) << endl; // add another star and it produces the contents of the array
    }
}