class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack:
    def __init__(self):
        self.top = None

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.top
        self.top = new_node
        return True

    def pop(self):
        if self.top is None:
            return -1   
        result = self.top.value
        self.top = self.top.next
        return result


def main():
    s1 = Stack()
    for i in range(1, 6):
        s1.push(i)

    while True:
        t = s1.pop()
        if t == -1:
            break
        print(t)


if __name__ == "__main__":
    main()
