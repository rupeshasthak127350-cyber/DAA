#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return;

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {

    int V = 5;
    int E = 7;

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgeCount = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (Edge edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV) {

            cout << u << " - " << v
                 << " : " << weight << endl;

            totalCost += weight;
            edgeCount++;

            unionSet(parent, rank, u, v);

            if (edgeCount == V - 1)
                break;
        }
    }

    cout << "Minimum cost = " << totalCost << endl;

    return 0;
}
