#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void bfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (int neighbor : adjList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
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

    g.bfs(0);

    return 0;
}
