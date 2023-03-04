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
    /**
     * Add a value to the queue.
     *
     * @param value The value to add.
     * @param group The group of the value or -1 to create a new group.
     */
    void enqueue(T value, int group = -1)
    {
        if (group == -1)
        {
            group = _findNewID();
            _groupQueue.enqueue(group);
            _groupedValues[group] = Queue<T>();
        }
        _groupedValues[group].enqueue(value);
    }

    /**
     * Remove a value from the queue.
     * Calling this on an empty queue is undefined behavior.
     *
     * @return The value that was removed.
     */
    T dequeue()
    {
        Queue<T>& firstGroup = _groupedValues[_groupQueue.front()];
        T value              = firstGroup.dequeue();

        if (firstGroup.empty())
        {
            // If the group is empty, remove it from our queue entirely.
            _groupQueue.dequeue();
        }

        return value;
    }

    T& front()
    {
        return _groupedValues[_groupQueue.front()].front();
    }

    bool empty()
    {
        return _groupQueue.empty();
    }
};
} // namespace israeli_queue
