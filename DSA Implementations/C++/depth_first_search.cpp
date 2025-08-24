#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

// Graph class
class Graph
{
private:
    int numVertices;
    bool weighted;
    vector<list<pair<int, int>>> adjLists; // adjacency list (pair(vertex, weight))

public:
    Graph(int vertices, bool isWeighted)
    {
        numVertices = vertices;
        weighted = isWeighted;
        adjLists.resize(vertices); // resize vector to hold adjacency lists for each vertex
    }

    // Function to add a directed edge
    void addSingleEdge(int src, int dest, int weight)
    {
        adjLists[src].emplace_back(dest, weighted ? weight : 1); // add edge with weight or default to 1
    }

    // Function to add an edge (handles directed/undirected graph)
    void addEdge(int src, int dest, bool directed, int weight)
    {
        addSingleEdge(src, dest, weight); // add directed edge
        if (!directed)
        {
            addSingleEdge(dest, src, weight); // add the reverse edge for undirected graph
        }
    }

    // Function to print the graph (adjacency list)
    void printGraph()
    {
        cout << "Adjacency List Representation: " << endl;
        for (int v = 0; v < numVertices; v++)
        {
            cout << v << " : ";
            for (auto &neighbor : adjLists[v])
            {
                if (weighted)
                {
                    cout << neighbor.first << "(" << neighbor.second << ") ";
                }
                else
                {
                    cout << neighbor.first << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    // DFS Traversal function
    void DFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        stack<int> frontier;

        frontier.push(startVertex);
        cout << "DFS Traversal starting from vertex " << startVertex << ": " << endl;

        while (!frontier.empty())
        {
            int current = frontier.top();
            frontier.pop();

            if (!visited[current])
            {
                visited[current] = true;
                cout << current << " ";

                for (auto &neighbor : adjLists[current])
                {
                    if (!visited[neighbor.first])
                    {
                        frontier.push(neighbor.first);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int vertices, edges, directed, weighted;

    cout << "Enter the number of vertices (Maximum 100): ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Is the graph directed? (0 = No, 1 = Yes): ";
    cin >> directed;

    cout << "Is the graph weighted? (0 = No, 1 = Yes): ";
    cin >> weighted;

    Graph graph(vertices, weighted);

    cout << "Enter the edges one by one:- " << endl;

    for (int i = 0; i < edges; i++)
    {
        int s, d, w = 1;
        cout << "Edge " << i + 1 << ": ";
        if (weighted)
        {
            cin >> s >> d >> w;
        }
        else
        {
            cin >> s >> d;
        }
        graph.addEdge(s, d, directed, w);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    graph.printGraph();     // print the adjacency list
    graph.DFS(startVertex); // perform DFS traversal

    return 0;
}
