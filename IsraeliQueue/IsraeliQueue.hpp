#pragma once
#include "Queue.hpp"
#include <unordered_map>

namespace israeli_queue
{
template <class T> class IsraeliQueue
{
private:
    Queue<int> _groupQueue;
    std::unordered_map<int, Queue<T>> _groupedValues;
    int _idCounter = 1;

    /**
     * Returns an unused group id.
     */
    int _findNewID()
    {
        int id = _idCounter++;

        // Check if there was an overflow in `_idCounter`.
        if (id < 0)
        {
            _idCounter = 1;
            while (_groupedValues.find(_idCounter) != _groupedValues.end())
            {
                _idCounter++;
            }
            id = _idCounter;
        }

        return id;
    }

public:
    void enqueue(T value, int group = -1);
    T dequeue();
};
} // namespace israeli_queue
