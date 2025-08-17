class Graph:
    def __init__(self, vertices):
        self.numVertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, src, dest):
        self.adjMatrix[src][dest] = 1
        self.adjMatrix[dest][src] = 1

    def dfs_recursive(self, vertex, visited):
        visited[vertex] = True
        print(vertex, end=" ")

        for i in range(self.numVertices):
            if self.adjMatrix[vertex][i] == 1 and not visited[i]:
                self.dfs_recursive(i, visited)

    def dfs(self, start_vertex):
        visited = [False] * self.numVertices
        print(f"DFS Traversal starting from vertex {start_vertex}:", end=" ")
        self.dfs_recursive(start_vertex, visited)
        print()

def main():
    g = Graph(6)

    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 4)
    g.add_edge(3, 5)
    g.add_edge(4, 5)

    g.dfs(0)


if __name__ == "__main__":
    main()