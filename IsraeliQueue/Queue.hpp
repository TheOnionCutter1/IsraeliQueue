#pragma once

namespace israeli_queue
{
template <class T> class Node
{
public:
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value) : value(value), next(nullptr), prev(nullptr)
    {
    }
};

template <class T> class Queue
{
private:
    Node<T>* _head;
    Node<T>* _tail;

public:
    Queue() : _head(nullptr), _tail(nullptr)
    {
    }

    void enqueue(const T& value)
    {
        if (!_head)
        {
            _head = new Node<T>(value);
            _tail = new Node<T>(value);
        }
        else
        {
            _tail->next       = new Node<T>(value);
            _tail->next->prev = _tail;
            _tail             = _tail->next;
        }
    }

    T dequeue();
};
}; // namespace israeli_queue
