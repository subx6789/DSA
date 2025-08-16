#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

void printList(const std::list<int> &lst)
{

    for (int value : lst)
    {
        std::cout << value << " - ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> number_list;

    for (int i = 1; i <= 25; i++)
    {
        number_list.push_front(i);
    }

    std::cout << "List after inserting 25 nodes:" << std::endl;
    printList(number_list);

    auto it_find = std::find(number_list.begin(), number_list.end(), 13);

    if (it_find != number_list.end())
    {
        std::cout << "Found node with value: " << *it_find << std::endl;

        auto it_insert_pos = std::next(it_find);
        number_list.insert(it_insert_pos, 75);

        std::cout << "List after inserting 75 after 13:" << std::endl;
        printList(number_list);

        auto it_remove = std::find(number_list.begin(), number_list.end(), 75);
        if (it_remove != number_list.end())
        {
            number_list.erase(it_remove);
        }

        std::cout << "List after removing node with value 75:" << std::endl;
        printList(number_list);
    }
    else
    {
        std::cout << "Node with value 13 not found." << std::endl;
    }

    return 0;
}