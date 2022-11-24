#ifndef LIST_H
#define LIST_H
using namespace std;

template <class T>
class List
{ // A finite ordered list with zero or more elements.
public:
    List(int queueCapcity = 10);
    // Create and empty queue whose initial capicity is queueCapicity

    ~List();
    // destructor

    int IsEmpty() const;
    // If number of element in the queue is 0, return 1 else return 0

    T &Front() const;
    // Return the element at the front og the queue

    T &Rear() const;
    // Return the element at the rear of the queue

    int getFront() const { return front; }

    int getRear() const { return rear; }

    int getSize() const;

    int getElement(int loc) const;

    void Delete(int k);

    void Add(int k);

    void Push(const T &item);
    // Insert item at rear of the queue

    void Pop();
    // Delete the front element of the queue

    void changeSize(const int newSize);
    // resizing the queue array

    template <typename U>
    friend ostream &operator<<(ostream &os, List<U> &s);

private:
    T *queue;     // array for queue elements
    int front,    // one counterclockwise from front
        rear,     // array position of rear element
        capacity; // capacity of queue array
};
#endif