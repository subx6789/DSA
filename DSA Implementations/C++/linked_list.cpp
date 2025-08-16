#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void printList(const list<int> &lst)
{
    for (int value : lst)
    {
        cout << value << " - ";
    }
    cout << endl;
}

int main()
{
    list<int> number_list;

    for (int i = 1; i <= 25; i++)
    {
        number_list.push_front(i);
    }

    cout << "List after inserting 25 nodes:" << endl;
    printList(number_list);

    auto it_find = find(number_list.begin(), number_list.end(), 13);

    if (it_find != number_list.end())
    {
        cout << "Found node with value: " << *it_find << endl;

        auto it_insert_pos = next(it_find);
        number_list.insert(it_insert_pos, 75);

        cout << "List after inserting 75 after 13:" << endl;
        printList(number_list);

        auto it_remove = find(number_list.begin(), number_list.end(), 75);
        if (it_remove != number_list.end())
        {
            number_list.erase(it_remove);
        }

        cout << "List after removing node with value 75:" << endl;
        printList(number_list);
    }
    else
    {
        cout << "Node with value 13 not found." << endl;
    }

    return 0;
}