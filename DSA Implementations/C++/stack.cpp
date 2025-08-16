#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> myStack;

    for (int i = 1; i <= 5; ++i)
    {
        myStack.push(i);
    }

    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }

    return 0;
}