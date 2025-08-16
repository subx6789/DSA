#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> myQueue;

    for (int i = 1; i <= 5; ++i)
    {
        myQueue.push(i);
    }

    while (!myQueue.empty())
    {
        cout << myQueue.front() << endl;
        myQueue.pop();
    }

    return 0;
}