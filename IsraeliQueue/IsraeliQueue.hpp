#pragma once
#include "Queue.hpp"
#include <unordered_map>

namespace israeli_queue
{
template <class T> class IsraeliQueue
{
    Queue<int> groupQueue;
    std::unordered_map<int, Node<T>> groupedValues;

    void enqueue(T value, int group = -1);
    T dequeue();
};
} // namespace israeli_queue
