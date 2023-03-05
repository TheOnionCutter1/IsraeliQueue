#include <IsraeliQueue.hpp>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

using israeli_queue::IsraeliQueue;

void simple_add_test(IsraeliQueue<int>& q)
{
    int num = 0;

    for (int i = 0; i < 20; i++)
    {
        num = rand() % 50;
        std::cout << "Adding " << num << " to the queue" << std::endl;
        q.enqueue(num);
    }
    for (int i = 0; i < 20; i++)
    {
        std::cout << "Popping " << q.dequeue() << " from the queue" << std::endl;
    }
}

void add_with_groups(IsraeliQueue<int>& q)
{
    int num = 0;

    for (int i = 0; i < 20; i++)
    {
        num = rand() % 50;
        std::cout << "Adding " << num << " to the queue, group " << (i % 5 + 1)
                  << std::endl;
        q.enqueue(num, i % 5 + 1);
    }
    for (int i = 0; i < 20; i++)
    {
        std::cout << "Popping " << q.dequeue() << " from the queue" << std::endl;
    }
}

void alert_next_test()
{
    int counter = 3;

    std::cout << "Press any key to move to the next test...";
    getchar();
    std::cout << "Next test is in ";
    for (int i = counter; i > 0; i--)
    {
        std::cout << i;
        for (int j = 0; j < 5; j++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::cout << '.';
            std::cout.flush();
        }
    }
    std::cout << std::endl;
}

int main()
{
    IsraeliQueue<int> q;

    std::cout << "Israeli queue demo" << std::endl;
    srand(time(nullptr));
    simple_add_test(q);
    alert_next_test();
    add_with_groups(q);

    return 0;
}
