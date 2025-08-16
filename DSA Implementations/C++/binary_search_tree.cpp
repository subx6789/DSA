#include <iostream>
#include <memory>
using namespace std;

struct TreeNode
{
    int value;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void printTabs(int numTabs)
{
    for (int i = 0; i < numTabs; i++)
    {
        cout << "\t";
    }
}

void printTreeRec(const unique_ptr<TreeNode> &root, int level)
{
    if (!root)
    {
        printTabs(level);
        cout << "---<empty>---\n";
        return;
    }
    printTabs(level);
    cout << "Value: " << root->value << "\n";

    printTabs(level);
    cout << "left\n";
    printTreeRec(root->left, level + 1);

    printTabs(level);
    cout << "right\n";
    printTreeRec(root->right, level + 1);

    printTabs(level);
    cout << "Done\n";
}

void printTree(const unique_ptr<TreeNode> &root)
{
    printTreeRec(root, 0);
}

bool insertNumber(unique_ptr<TreeNode> &root, int value)
{
    if (!root)
    {
        root = make_unique<TreeNode>(value);
        return true;
    }
    if (value == root->value)
        return false;

    if (value < root->value)
    {
        return insertNumber(root->left, value);
    }
    else
    {
        return insertNumber(root->right, value);
    }
}

bool findNumber(const unique_ptr<TreeNode> &root, int value)
{
    if (!root)
        return false;
    if (root->value == value)
        return true;

    if (value < root->value)
        return findNumber(root->left, value);
    else
        return findNumber(root->right, value);
}

int main()
{
    unique_ptr<TreeNode> root = nullptr;

    insertNumber(root, 15);
    insertNumber(root, 11);
    insertNumber(root, 24);
    insertNumber(root, 5);
    insertNumber(root, 19);
    insertNumber(root, 16);

    printTree(root);

    cout << 16 << " (" << findNumber(root, 16) << ")\n";
    cout << 15 << " (" << findNumber(root, 15) << ")\n";
    cout << 5 << " (" << findNumber(root, 5) << ")\n";
    cout << 115 << " (" << findNumber(root, 115) << ")\n";
    cout << 1 << " (" << findNumber(root, 1) << ")\n";
    cout << 7 << " (" << findNumber(root, 7) << ")\n";

    return 0;
}
