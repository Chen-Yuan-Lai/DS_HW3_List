#ifndef LIST_H
#define LIST_H
using namespace std;

template <class T>
class List
{ // A circular quene
public:
    List(int ListCapicity = 10);
    // create an empty quene whose initial is queneCapicity

    int IsEmpty() const;
    // If number of elements in the quene is 0, return true else return false

    T &Front() const;
    // Return the element at the front of the quene

    T &Rear() const;
    // Return the element at the rear of the quene

    void Push(const T &item);
    // Insert item at the rear of the quene

    void Pop();
    // Delete the front element of the quene
private:
    T *quene;     // array for quene
    int front,    // one counterclockwise from front
        rear,     // array position of rear element
        capacity; // capacity of quene array
};
#endif