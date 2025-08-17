from collections import deque

class Graph:
    def __init__(self, vertices):
        self.numVertices = vertices
        self.adjList = [[] for _ in range(vertices)]

    def addEdge(self, src, dest):
        self.adjList[src].append(dest)
        self.adjList[dest].append(src)  

    def bfs(self, startVertex):
        visited = [False] * self.numVertices
        queue = deque([startVertex])
        visited[startVertex] = True

        print(f"BFS Traversal starting from vertex {startVertex}: ", end="")

        while queue:
            currentVertex = queue.popleft()
            print(currentVertex, end=" ")

            for neighbor in self.adjList[currentVertex]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)

        print()

def main():
    g = Graph(6)

    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 3)
    g.addEdge(1, 4)
    g.addEdge(2, 4)
    g.addEdge(3, 5)
    g.addEdge(4, 5)

    g.bfs(0)

if __name__ == "__main__":
    main()
