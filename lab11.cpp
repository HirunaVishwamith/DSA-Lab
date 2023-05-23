#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a graph edge
struct Edge
{
    int destination;
    int weight;
};

// Function to add an edge to the graph
void addEdge(vector<vector<Edge>> &graph, int source, int destination, int weight)
{
    Edge edge;
    edge.destination = destination;
    edge.weight = weight;

    graph[source].push_back(edge);

    // Since the graph is undirected, add an edge in the opposite direction as well
    edge.destination = source;
    graph[destination].push_back(edge);
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Edge>> &graph, int vertices)
{
    vector<int> key(vertices, INT_MAX);    // Key values used to pick minimum weight edge
    vector<bool> visited(vertices, false); // To track visited vertices
    vector<int> parent(vertices, -1);      // Array to store the MST

    // Priority queue to select the minimum key vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startVertex = 0; // Start from the first vertex
    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        // Traverse all adjacent vertices of u
        for (auto edge : graph[u])
        {
            int v = edge.destination;
            int weight = edge.weight;

            if (visited[v] == false && weight < key[v])
            {
                // Update key value and parent index
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < vertices; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    int vertices = 6; // Number of vertices in the graph

    vector<vector<Edge>> graph(vertices); // Adjacency list to represent the graph

    // Adding edges to the graph
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 0, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 10);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 3, 2, 3);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 4, 1, 10);
    addEdge(graph, 4, 3, 5);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 5, 0, 1);
    addEdge(graph, 5, 2, 10);
    addEdge(graph, 5, 4, 4);

    // Find the minimum spanning tree using Prim's algorithm
    primMST(graph, vertices);

    return 0;
}
