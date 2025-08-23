#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// Graph structure using STL
class Graph
{
public:
    int numVertices;            // Number of vertices
    vector<list<int>> adjLists; // Adjacency list using STL list

    // Constructor to create a graph with given vertices
    Graph(int vertices)
    {
        numVertices = vertices;
        adjLists.resize(vertices); // Resize vector to hold adjacency lists for each vertex
    }

    // Function to add a directed edge from src -> dest
    void addEdge(int src, int dest, bool directed)
    {
        adjLists[src].push_back(dest); // Add directed edge from src to dest
        if (!directed)                 // If the graph is undirected, add the reverse edge as well
        {
            adjLists[dest].push_back(src);
        }
    }

    // Function to print the adjacency list of the graph
    void printGraph()
    {
        cout << "\nAdjacency List Representation:\n";
        for (int v = 0; v < numVertices; v++)
        {
            cout << v << " -> ";
            for (int adjVertex : adjLists[v])
            {
                cout << adjVertex << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    // BFS Traversal function starting from the given startVertex
    void BFS(int startVertex)
    {
        vector<bool> visited(numVertices, false); // Vector to track visited nodes
        queue<int> frontier;                      // Queue to hold the nodes to explore

        visited[startVertex] = true; // Mark the start vertex as visited
        frontier.push(startVertex);  // Enqueue the start vertex

        cout << "BFS Traversal starting from vertex " << startVertex << ":\n";

        while (!frontier.empty()) // While there are nodes to explore
        {
            int currentVertex = frontier.front(); // Dequeue a node
            frontier.pop();
            cout << currentVertex << " ";

            // Visit all adjacent vertices
            for (int adjVertex : adjLists[currentVertex])
            {
                if (!visited[adjVertex]) // If the adjacent vertex hasn't been visited
                {
                    visited[adjVertex] = true; // Mark as visited
                    frontier.push(adjVertex);  // Enqueue the adjacent vertex
                }
            }
        }
        cout << "\n";
    }
};

int main()
{
    int vertices, edges, directed;
    cout << "Enter the number of vertices (Maximum 100): ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Is the graph directed? (0 = No, 1 = Yes): ";
    cin >> directed;

    Graph graph(vertices); // Create a graph with the given number of vertices

    cout << "Enter the edges (source destination) one by one:\n";
    for (int i = 0; i < edges; i++)
    {
        int s, d;
        cin >> s >> d;
        graph.addEdge(s, d, directed); // Add the edge to the graph
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    graph.printGraph(); // Print the adjacency list

    graph.BFS(startVertex); // Perform BFS traversal

    return 0;
}
