#include <iostream>
#include <iomanip>
#include "List.h"
using namespace std;

template <class T>
List<T>::List(int queueCapcity) : capacity(queueCapcity)
{ // constructor
    try
    {
        if (capacity < 1)
        {
            throw e1("List capacity must be > 0");
        }
        queue = new T[capacity];
        front = rear = 0;
    }
    catch (e1 &a)
    {
        cout << a.content() << endl;
        return;
    }
}

template <class T>
List<T>::~List()
{
    delete[] queue;
}

template <class T>
inline int List<T>::IsEmpty() const
{
    return front == rear;
}

template <class T>
inline T &List<T>::Front() const
{
    try
    {
        if (IsEmpty())
        {
            throw e1("List is empty. No front element");
        }
        return queue[(front + 1) % capacity];
    }
    catch (e1 &a)
    {
        cout << a.content() << endl;
    }
    return;
}

template <class T>
inline T &List<T>::Rear() const
{
    if (IsEmpty())
    {
        throw "List is empty. No rear element";
    }
    return queue[rear];
}

template <class T>
T &List<T>::getElement(const int k) const
{
    int pos;
    try
    {
        if (IsEmpty())
            throw e1("List is empty");

        pos = (front + k) % capacity;

        if (pos > rear)
            throw e1("The list dosen't have this element");

        return queue[pos];
    }
    catch (e1 &a)
    {
        cout << a.content() << endl;
        throw; // re-throw to stop the function
    }
}

template <class T>
void List<T>::changeSize(const int newSize)
{ // allocate an array with new size
    if (newSize < capacity)
    {
        throw "New size must be >= number of capacity";
    }
    T *newQueue = new T[newSize];
    int start = (front + 1) % capacity;
    if (start < 2)
    { // no wrap around
        copy(queue + start, queue + start + capacity - 1, newQueue);
    }
    else
    {
        copy(queue + start, queue + capacity, newQueue); // copy first part of element
        copy(queue, queue + rear + 1, newQueue + capacity - start);
    }
    // switch to newQueue
    front = newSize - 1;
    rear = capacity - 2;
    capacity = newSize;
    delete[] queue;
    queue = newQueue;
}

template <class T>
void List<T>::Delete(int k)
{ // Delete the kth element
    if (IsEmpty())
    {
        throw "List is empty. Caannot delete";
    }
    else if (k == (front + 1) % capacity)
    { // when queue only have one element or k is located in front
        front = (front + 1) % capacity;
        queue[front].~T(); // destructor for T
    }
    else
    {
        if (k != rear)
        { // move each element from k toward rear one index
            while (k % capacity != rear)
            {
                queue[k % capacity] = queue[(k + 1) % capacity];
                k = (k + 1) % capacity;
            }
        }
        // rear come back one index
        rear--;
        if (rear < 0)
        {
            rear = capacity + rear;
        }
    }
}

template <class T>
void List<T>::Add(int k)
{
    if (IsEmpty())
    {
        throw "List is empty. Caannot delete";
    }
    else if (k == (front + 1) % capacity)
    { // when queue only have one element or k is located in front
        Pop();
    }
}

template <class T>
void List<T>::Push(const T &x)
{ // Add x at rear of queue
    if ((rear + 1) % capacity == front)
    { // queue full, double capacity
        changeSize(2 * capacity);
    }
    rear = (rear + 1) % capacity;
    queue[rear] = x;
}

template <class T>
void List<T>::Pop()
{ // Delete front element from queue
    if (IsEmpty())
    {
        throw "List is empty. Caannot delete";
    }
    front = (front + 1) % capacity;
    queue[front].~T(); // destructor for T
}

template <class T>
ostream &operator<<(ostream &os, List<T> &s)
{
    // print array index
    for (int i = 0; i < s.capacity; i++)
    {
        os << "[" << i << "]"
           << "  ";
    }
    if (!s.IsEmpty())
    {
        os << endl;
        for (int i = 0; i < s.capacity; i++)
        {
            if (s.front + 1 > s.rear)
            {
                i > s.rear &&i <= s.front ? os << "     " : os << " " << s.queue[i] << "   ";
            }
            else
            {
                i <= s.rear &&i > s.front ? os << " " << s.queue[i] << "   " : os << "     ";
            }
        }
    }

    os << endl;
    return os;
}
