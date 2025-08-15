class Node:
    def __init__(self, value):
        self.value = value  
        self.next = None    
        self.prev = None    

class DoublyLinkedList:
    def __init__(self):
        self.head = None 

    def print_list(self):
        temp = self.head
        output_str = ""
        while temp is not None:
            output_str += f"{temp.value} - "
            temp = temp.next
        print(output_str)

    def insert_at_head(self, value):
        new_node = Node(value)
        new_node.next = self.head

        if self.head is not None:
            self.head.prev = new_node

        self.head = new_node

    def find_node(self, value):
        temp = self.head
        while temp is not None:
            if temp.value == value:
                return temp
            temp = temp.next
        return None

    def insert_after_node(self, node_to_insert_after, value):
        if node_to_insert_after is None:
            print("Error: The node to insert after cannot be None.")
            return

        new_node = Node(value)

        new_node.next = node_to_insert_after.next
        new_node.prev = node_to_insert_after

        if new_node.next is not None:
            new_node.next.prev = new_node

        node_to_insert_after.next = new_node

    def remove_node(self, value_to_remove):
        node_to_remove = self.find_node(value_to_remove)

        if node_to_remove is None:
            return

        if node_to_remove == self.head:
            self.head = node_to_remove.next

        if node_to_remove.next is not None:
            node_to_remove.next.prev = node_to_remove.prev

        if node_to_remove.prev is not None:
            node_to_remove.prev.next = node_to_remove.next

if __name__ == "__main__":
    dll = DoublyLinkedList()

    for i in range(1, 26):
        dll.insert_at_head(i)

    print("List after inserting 25 nodes:")
    dll.print_list()

    tmp = dll.find_node(13)
    if tmp:
        print(f"Found node with value: {tmp.value}")

        print(f"List after inserting node with value 75 after node with value {tmp.value}:")
        dll.insert_after_node(tmp, 75)
        dll.print_list()

        print("List after removing node with value 75:")
        dll.remove_node(75)
        dll.print_list()
    else:
        print("Node with value 13 not found.")