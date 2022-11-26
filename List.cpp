#include <iostream>
#include <iomanip>
#include "List.h"
using namespace std;

template <class T>
List<T>::List(int queueCapcity) : capacity(queueCapcity)
{ // constructor

    if (capacity < 1)
    {
        throw e1("List capacity must be > 0");
    }
    queue = new T[capacity];
    front = rear = 0;
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
    if (IsEmpty())
    {
        throw e1("List is empty. No front element");
    }
    return queue[(front + 1) % capacity];
}

template <class T>
inline T &List<T>::Rear() const
{
    if (IsEmpty())
    {
        throw e1("List is empty. No rear element");
    }
    return queue[rear];
}

template <class T>
T &List<T>::getElement(const int k) const
{
    if (IsEmpty())
        throw e1("List is empty");
    // how many elements in the list
    int elementNum = rear > front ? rear - front : capacity + rear - front;

    if (k < 1 || k > elementNum)
        throw e1("unavailable k");

    int pos = (front + k) % capacity;

    return queue[pos];
}

template <class T>
void List<T>::changeSize(const int newSize)
{ // allocate an array with new size
    if (newSize < capacity)
        throw e1("New size must be >= number of capacity");

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
        throw e1("List is empty");
    // how many elements in the list
    int elementNum = rear > front ? rear - front : capacity + rear - front;

    if (k < 1 || k > elementNum)
        throw e1("unavailable k");
    // get index
    int pos = (front + k) % capacity;
    // how many elements in the list
    if (k == 1)
    { // when queue only have one element or the kth element is the (front + 1) of the queue
        front = (front + 1) % capacity;
        queue[front].~T(); // destructor for T
    }
    else
    {
        queue[pos].~T(); // destructor for T
        while (pos != rear)
        { // step back one element from the kth element
            queue[pos] = queue[(pos + 1) % capacity];
            pos = (pos + 1) % capacity;
        }
        // rear come back one index
        if (--rear < 0)
            rear = capacity + rear;
    }
}

template <class T>
void List<T>::Insert(const T &y, const int k)
{ // Insert an element y after the kth element.
    if (IsEmpty())
        throw e1("List is empty");

    // how many elements in the list
    int elementNum = rear > front ? rear - front : capacity + rear - front;

    if (k < 1 || k > elementNum)
        throw e1("unavailable k");

    if ((rear + 1) % capacity == front)
    { // queue full, double capacity
        changeSize(2 * capacity);
    }
    // get index
    int pos = (front + k) % capacity;

    if (pos == rear)
    { // when the kth element is the rear of the list
        rear = (rear + 1) % capacity;
        queue[rear] = y;
    }
    else
    {

        int p = front;
        int num = 0;
        // loop k+1 times
        while (num < k)
        { // use front to store new element
            queue[p] = queue[(p + 1) % capacity];
            p = (p + 1) % capacity;
            num++;
        }
        queue[p] = y;
        front--;
        if (front < 0)
            front = capacity + front;
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
        string index = "[" + to_string(i) + "]";
        os << left << setw(6) << index;
    }
    if (!s.IsEmpty())
    {
        os << endl;
        for (int i = 0; i < s.capacity; i++)
        {
            if (s.front + 1 > s.rear)
            {
                if (i > s.rear && i <= s.front)
                    os << setw(6) << " ";
                else
                    os << left << setw(6) << to_string(s.queue[i]);
            }
            else
            {
                if (i <= s.rear && i > s.front)
                    os << left << setw(6) << to_string(s.queue[i]);
                else
                    os << setw(6) << " ";
            }
        }
    }

    os << endl;
    return os;
}
