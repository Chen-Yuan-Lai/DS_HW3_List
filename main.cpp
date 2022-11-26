#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
    try
    {
        List<int> a;
        a.Push(1);
        a.Push(2);
        a.Push(3);
        a.Push(4);
        a.Push(5);
        a.Push(6);
        a.Push(7);
        a.Push(8);
        a.Push(9);
        a.Pop();
        a.Push(10);
        int y = 20;
        cout << a << endl;
        a.Insert(y, 7);
        // cout << a.getFront() << endl;
        // cout << a.getRear() << endl;
        // cout << a.getElement(1) << endl;
        // cout << a.getElement(10) << endl;
        cout << a << endl;
    }
    catch (e1 &b)
    {
        cout << b.content() << endl;
    }
    return 0;
}