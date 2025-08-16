class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, value):
        newnode = Node(value)
        if self.tail is not None:
            self.tail.next = newnode
        self.tail = newnode
        if self.head is None:
            self.head = newnode
        return True

    def dequeue(self):
        if self.head is None:
            return -1
        result = self.head.value
        self.head = self.head.next
        if self.head is None:
            self.tail = None
        return result

def main():
    q = Queue()

    for i in range(1, 6):
        q.enqueue(i)

    t = q.dequeue()
    while t != -1:
        print(t)
        t = q.dequeue()


if __name__ == "__main__":
    main()