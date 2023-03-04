#pragma once

#include <cstddef>

namespace israeli_queue
{
template <class T> class Node
{
public:
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : value(value), next(NULL), prev(NULL)
    {
    }
};

template <class T> class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Queue() : head(NULL), tail(NULL)
    {
    }

    void enqueue(T value)
    {
        if (!head)
        {
            head = new Node<T>(value);
            tail = new Node<T>(value);
        }
        else
        {
            tail->next       = new Node<T>(value);
            tail->next->prev = tail;
            tail             = tail->next;
        }
    }

    T dequeue();
};
}; // namespace israeli_queue
