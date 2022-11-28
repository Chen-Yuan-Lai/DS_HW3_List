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
    int getSize() const { return capacity; }
    // Return the size of the list
    T &getElement(const int k) const;
    // Return ith element
    void Delete(const int k);
    // Delete the kth element
    void Insert(const T &y, const int k);
    // Insert an element y after the kth element.
    void Push(const T &item);
    // Insert item at rear of the queue

    void Pop();
    // Delete the front element of the queue

    void changeSize(const int newSize);
    // resizing the queue array

    template <typename U>
    friend ostream &operator<<(ostream &os, List<U> &s);

private:
    T *queue;       // array for queue elements
    int front,      // one counterclockwise from front
        rear,       // array position of rear element
        elementNum, // numbers of elements in the list
        capacity;   // capacity of queue array
};

// define custom exception type
class e1 : public exception
{
public:
    e1(string msg) : message(msg) {}
    // override std:: what()
    string content()
    {
        return message;
    }

private:
    string message;
};
#endif