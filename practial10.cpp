
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store edges
struct Edge {
    int u, v, weight;
};

// Find the parent of a vertex
int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

// Combine two sets
void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return;

    // Union by rank
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Main function
int main() {

    int V = 5;
    int E = 7;

    // Define graph edges
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    // Initialize parent and rank arrays
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgeCount = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    // Select edges for Minimum Spanning Tree
    for (Edge edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // Check whether adding edge creates a cycle
        if (parentU != parentV) {

            cout << u << " - " << v
                 << " : " << weight << endl;

            totalCost += weight;
            edgeCount++;

            // Merge two sets
            unionSet(parent, rank, u, v);

            // Stop after selecting V-1 edges
            if (edgeCount == V - 1)
                break;
        }
    }

    // Display minimum cost
    cout << "Minimum cost = " << totalCost << endl;

    return 0;
}
