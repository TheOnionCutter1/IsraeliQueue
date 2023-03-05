#pragma once
#include "Queue.hpp"
#include <unordered_map>
#include <utility>

namespace israeli_queue
{
template <class T> class IsraeliQueue
{
private:
    Queue<unsigned int> _groupQueue;
    std::unordered_map<unsigned int, Queue<T>> _groupedValues;
    unsigned int _idCounter = 0;

    /**
     * Returns an unused group id.
     */
    unsigned int _findNewID()
    {
        unsigned int id = 0;

        _idCounter++;
        // Check if there was an overflow in `_idCounter`.
        if (_idCounter == 0)
        {
            _idCounter++;
        }
        while (_groupedValues.find(_idCounter) != _groupedValues.end())
        {
            _idCounter++;
        }
        id = _idCounter;

        return id;
    }

public:
    /**
     * Add a value to the queue.
     *
     * @param value The value to add.
     * @param group The group of the value or 0 to create a new group.
     * If the group does not exist, a new group with
     * the specified id will be created.
     *
     * @return The ID of the group (useful when passing 0 in `group`).
     */
    unsigned int enqueue(T value, unsigned int group = 0)
    {
        if (group == 0)
        {
            group = _findNewID();
        }
        // Check if it is a new group.
        if (_groupedValues.find(group) == _groupedValues.end())
        {
            _groupQueue.enqueue(group);
            _groupedValues.insert(std::make_pair(group, Queue<T>()));
        }
        _groupedValues[group].enqueue(value);

        return group;
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
            _groupedValues.erase(_groupQueue.dequeue());
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
