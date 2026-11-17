
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find the minimum key value
int findMin(vector<int>& key, vector<bool>& used, int V)
{
    int minValue = INT_MAX;
    int index = -1;

    for (int i = 0; i < V; i++)
    {
        if (!used[i] && key[i] < minValue)
        {
            minValue = key[i];
            index = i;
        }
    }
    return index;
}

// Function to implement Prim's Algorithm
void prim(vector<vector<int>>& graph, int V)
{
    // Initialize key, parent and used arrays
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> used(V, false);

    key[0] = 0;

    // Find Minimum Spanning Tree
    for (int count = 0; count < V - 1; count++)
    {
        int u = findMin(key, used, V);
        used[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !used[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Calculate total minimum cost
    int total = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 1; i < V; i++)
    {
        int weight = graph[i][parent[i]];

        cout << parent[i] << " - "
             << i << " : "
             << weight << endl;

        total += weight;
    }

    cout << "Minimum cost = " << total << endl;
}

// Main function
int main()
{
    int V = 6;

    // Define the adjacency matrix
    vector<vector<int>> graph =
    {
        {0, 4, 0, 7, 0, 0},
        {4, 0, 6, 2, 5, 0},
        {0, 6, 0, 3, 3, 8},
        {7, 2, 3, 0, 1, 0},
        {0, 5, 3, 1, 0, 9},
        {0, 0, 8, 0, 9, 0}
    };

    // Call Prim's Algorithm
    prim(graph, V);

    return 0;
}
