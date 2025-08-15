class Node:
    def __init__(self, value):
        self.value = value  
        self.next = None    

class LinkedList:
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
        node_to_insert_after.next = new_node

    def remove_node(self, value_to_remove):
        current = self.head

        if current is not None and current.value == value_to_remove:
            self.head = current.next
            current = None 
            return

        prev = None
        while current is not None and current.value != value_to_remove:
            prev = current
            current = current.next

        if current is None:
            return

        prev.next = current.next
        current = None

if __name__ == "__main__":
    llist = LinkedList()

    for i in range(1,26):
        llist.insert_at_head(i)

    print("List after inserting 25 nodes:")
    llist.print_list()

    tmp = llist.find_node(13)
    if tmp:
        print(f"Found node with value: {tmp.value}")

        print(f"List after inserting node with value 75 after node with value {tmp.value}:")
        llist.insert_after_node(tmp, 75)
        llist.print_list()

        print("List after removing node with value 75:")
        llist.remove_node(75)
        llist.print_list()
    else:
        print("Node with value 13 not found.")