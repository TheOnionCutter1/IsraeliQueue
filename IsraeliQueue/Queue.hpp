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
            _tail = _head;
        }
        else
        {
            _tail->next       = new Node<T>(value);
            _tail->next->prev = _tail;
            _tail             = _tail->next;
        }
    }

    T dequeue()
    {
        T value = _head->value;

        delete _head;
        _head = _head->next;
        if (!_head)
        {
            _tail = nullptr;
        }
        else
        {
            _head->prev = nullptr;
        }

        return value;
    }

    ~Queue()
    {
        Node<T>* curr = _head;
        Node<T>* next = nullptr;

        _head = nullptr;
        _tail = nullptr;
        while (curr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
}; // namespace israeli_queue
