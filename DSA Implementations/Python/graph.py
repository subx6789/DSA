class Graph:
    def __init__(self, vertices):
        self.numVertices = vertices
        self.adjMatrix = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, src, dest):
        self.adjMatrix[src][dest] = 1
        self.adjMatrix[dest][src] = 1

    def print_graph(self):
        print("\nAdjacency Matrix:")
        for row in self.adjMatrix:
            print(" ".join(map(str, row)))

    def print_edges(self):
        print("\nGraph Representation (Edges):")
        for i in range(self.numVertices):
            connections = [str(j) for j in range(self.numVertices) if self.adjMatrix[i][j] == 1]
            if connections:
                print(f"Vertex {i} is connected to: {' '.join(connections)}")
            else:
                print(f"Vertex {i} is connected to: None")

def main():
    vertices = 5
    g = Graph(vertices)

    g.add_edge(0, 1)
    g.add_edge(0, 4)
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 3)
    g.add_edge(3, 4)

    g.print_graph()
    g.print_edges()

if __name__ == "__main__":
    main()
