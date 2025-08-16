#include <iostream>
#include <queue>

int main()
{
    std::queue<int> myQueue;

    for (int i = 1; i <= 5; ++i)
    {
        myQueue.push(i);
    }

    while (!myQueue.empty())
    {
        std::cout << myQueue.front() << std::endl;
        myQueue.pop();
    }

    return 0;
}