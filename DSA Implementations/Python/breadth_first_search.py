from collections import deque

class Graph:
    def __init__(self, vertices):
        self.numVertices = vertices
        self.adjLists = [[] for _ in range(vertices)]  # Create an adjacency list

    # Function to add a directed edge from src -> dest
    def addEdge(self, src, dest, directed):
        self.adjLists[src].append(dest)  # Add directed edge from src to dest
        if not directed:                 # If the graph is undirected, add the reverse edge as well
            self.adjLists[dest].append(src)

    # Function to print the adjacency list of the graph
    def printGraph(self):
        print("\nAdjacency List Representation:")
        for v in range(self.numVertices):
            print(f"{v} ->", " ".join(map(str, self.adjLists[v])))
        print()

    # BFS Traversal function starting from the given startVertex
    def BFS(self, startVertex):
        visited = [False] * self.numVertices  # List to track visited nodes
        frontier = deque([startVertex])       # Queue to hold nodes to explore
        visited[startVertex] = True           # Mark start vertex as visited

        print(f"BFS Traversal starting from vertex {startVertex}:")

        while frontier:  # While there are nodes to explore
            currentVertex = frontier.popleft()  # Dequeue a node
            print(currentVertex, end=" ")

            # Visit all adjacent vertices
            for adjVertex in self.adjLists[currentVertex]:
                if not visited[adjVertex]:  # If the adjacent vertex hasn't been visited
                    visited[adjVertex] = True  # Mark as visited
                    frontier.append(adjVertex)  # Enqueue the adjacent vertex
        print()

# Main function to interact with the user and run the BFS
def main():
    vertices = int(input("Enter the number of vertices (Maximum 100): "))
    edges = int(input("Enter the number of edges: "))
    directed = int(input("Is the graph directed? (0 = No, 1 = Yes): "))

    graph = Graph(vertices)  # Create a graph with the given number of vertices

    print("Enter the edges (source destination) one by one:")
    for _ in range(edges):
        s, d = map(int, input().split())
        graph.addEdge(s, d, directed)  # Add the edge to the graph

    startVertex = int(input("Enter the starting vertex for BFS: "))

    graph.printGraph()  # Print the adjacency list

    graph.BFS(startVertex)  # Perform BFS traversal

if __name__ == "__main__":
    main()
