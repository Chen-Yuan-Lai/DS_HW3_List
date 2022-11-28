#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
    string output;
    List<int> a;
    output = a.IsEmpty() ? "True" : "False";
    cout << output << endl;
    cout << a << endl;
    // push 0~8 in the list
    for (int i = 0; i < 9; i++)
    {
        a.Push(i);
    }
    output = a.IsEmpty() ? "True" : "False";
    cout << output << endl;
    cout << a << endl;
    cout << "The " << 3 << "th element is "
         << a.getElement(3) << endl;
    cout << "Size of the list is " << a.getSize() << endl;
    return 0;
}