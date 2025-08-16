class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def print_tabs(num_tabs):
    print("\t" * num_tabs, end="")


def print_tree_rec(root, level=0):
    if root is None:
        print_tabs(level)
        print("---<empty>---")
        return

    print_tabs(level)
    print(f"Value: {root.value}")

    print_tabs(level)
    print("left")
    print_tree_rec(root.left, level + 1)

    print_tabs(level)
    print("right")
    print_tree_rec(root.right, level + 1)

    print_tabs(level)
    print("Done")


def print_tree(root):
    print_tree_rec(root, 0)


def insert_number(root, value):
    if root is None:
        return TreeNode(value)

    if value == root.value:
        return root  

    if value < root.value:
        root.left = insert_number(root.left, value)
    else:
        root.right = insert_number(root.right, value)

    return root


def find_number(root, value):
    if root is None:
        return False
    if root.value == value:
        return True
    if value < root.value:
        return find_number(root.left, value)
    else:
        return find_number(root.right, value)

def main():
    root = None
    for num in [15, 11, 24, 5, 19, 16]:
        root = insert_number(root, num)

    print_tree(root)

    print(16, "(", find_number(root, 16), ")")
    print(15, "(", find_number(root, 15), ")")
    print(5, "(", find_number(root, 5), ")")
    print(115, "(", find_number(root, 115), ")")
    print(1, "(", find_number(root, 1), ")")
    print(7, "(", find_number(root, 7), ")")

if __name__ == "__main__":
    main()
