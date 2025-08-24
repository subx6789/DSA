class Graph:
    def __init__(self, vertices, weighted):
        self.numVertices = vertices
        self.weighted = weighted
        self.adjLists = [[] for _ in range(vertices)]  # adjacency list

    def add_single_edge(self, src, dest, weight):
        self.adjLists[src].append((dest, weight if self.weighted else 1))  # add edge with weight or default to 1

    def add_edge(self, src, dest, directed, weight):
        self.add_single_edge(src, dest, weight)  # add directed edge
        if not directed:
            self.add_single_edge(dest, src, weight)  # add the reverse edge for undirected graph

    def print_graph(self):
        print("Adjacency List Representation: ")
        for v in range(self.numVertices):
            print(f"{v} : ", end="")
            for neighbor in self.adjLists[v]:
                if self.weighted:
                    print(f"{neighbor[0]}({neighbor[1]}) ", end="")
                else:
                    print(f"{neighbor[0]} ", end="")
            print()

    def dfs(self, start_vertex):
        visited = [False] * self.numVertices
        stack = [start_vertex]
        print(f"DFS Traversal starting from vertex {start_vertex}: ")
        
        while stack:
            current = stack.pop()

            if not visited[current]:
                visited[current] = True
                print(current, end=" ")

                for neighbor in self.adjLists[current]:
                    if not visited[neighbor[0]]:
                        stack.append(neighbor[0])

        print()

# Main code
if __name__ == "__main__":
    vertices = int(input("Enter the number of vertices (Maximum 100): "))
    edges = int(input("Enter the number of edges: "))
    directed = int(input("Is the graph directed? (0 = No, 1 = Yes): "))
    weighted = int(input("Is the graph weighted? (0 = No, 1 = Yes): "))

    graph = Graph(vertices, weighted)

    print("Enter the edges one by one:- ")

    for i in range(edges):
        if weighted:
            s, d, w = map(int, input(f"Edge {i + 1}: ").split())
        else:
            s, d = map(int, input(f"Edge {i + 1}: ").split())
            w = 1  # default weight
        graph.add_edge(s, d, directed, w)

    start_vertex = int(input("Enter the starting vertex for DFS: "))

    graph.print_graph()  # print the adjacency list
    graph.dfs(start_vertex)  # perform DFS traversal