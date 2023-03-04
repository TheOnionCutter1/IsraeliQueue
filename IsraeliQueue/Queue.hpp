#pragma once

namespace israeli_queue
{
template <class T> class Node
{
public:
    T value;
    Node* next;
    Node* prev;
};

template <class T> class Queue
{
private:
public:
    void enqueue(T value);
    T dequeue();
};
}; // namespace israeli_queue
