#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
    List<int> a;
    a.Push(1);
    // a.Push(2);
    // a.Push(3);
    // a.Push(4);
    // a.Push(5);
    // a.Push(6);
    // a.Push(7);
    // a.Push(8);
    // a.Push(9);
    // a.Pop();
    // a.Push(10);
    // a.Delete(1);
    cout << a.getFront() << endl;
    cout << a.getRear() << endl;
    cout << a << endl;
    return 0;
}