#include <iostream>
#include "List.h"
using namespace std;

template <class T>
List<T>::List(int queueCapcity) : capacity(queueCapcity)
{
    if (capacity < 1)
    {
        throw "List capacity must be > 0";
        queue = new T[capacity];
        fill(queue, queue + capacity, 0); // initialise new array to 0
        front = rear = 0;
    }
}

template <class T>
List<T>::IsEmpty()
{
    return front == rear;
}

template <calss T>
inline T &List<T>::Front()
{
    if (IsEmpty())
    {
        throw "List is empty. No front element";
    }
    return queue[(front + 1) % capacity];
}

template <class T>
inline T &List<T>::Rear()
{
    if (IsEmpty())
    {
        throw "List is empty. No rear element";
    }
    return queue[rear];
}

template <class T>
void List<T>::changeSize(const int newSize)
{ // allocate an array with new size
    if (newSize < capacity)
    {
        throw "New size must be >= number of capacity";
    }
    T *newQueue = new T[newSize];
    fill(newQueue, newQueue + newSize, 0);
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
void List<T>::Push(const &x)
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
    for (int i = 0; i < s.capacity; i++)
    {
        os << s.queue[i] << endl;
    }
    return os;
}