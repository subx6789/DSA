#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int numVertices;
    vector<vector<int>> adjMatrix;

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

    void printGraph()
    {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printEdges()
    {
        cout << "\nGraph Representation (Edges):\n";
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << " is connected to: ";
            bool hasEdges = false;
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << j << " ";
                    hasEdges = true;
                }
            }
            if (!hasEdges)
            {
                cout << "None";
            }
            cout << endl;
        }
    }
};

int main()
{
    int vertices = 5;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    g.printEdges();

    return 0;
}
