#include <iostream>
#include <stack>

int main()
{
    std::stack<int> myStack;

    for (int i = 1; i <= 5; ++i)
    {
        myStack.push(i);
    }

    while (!myStack.empty())
    {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }

    return 0;
}