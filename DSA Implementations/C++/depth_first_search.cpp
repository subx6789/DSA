#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

    void dfsRecursive(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[vertex][i] == 1 && !visited[i])
            {
                dfsRecursive(i, visited);
            }
        }
    }

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int src, int dest)
    {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void dfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        dfsRecursive(startVertex, visited);
        cout << endl;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.dfs(0);

    return 0;
}
