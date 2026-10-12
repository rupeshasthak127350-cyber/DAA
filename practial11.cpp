#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V = 5;
    const int INF = INT_MAX / 2;

    vector<vector<int>> dist = {
        {0,   2,   INF, 6,   INF},
        {2,   0,   3,   8,   5},
        {INF, 3,   0,   INF, 7},
        {6,   8,   INF, 0,   9},
        {INF, 5,   7,   9,   0}
    };

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    cout << "Shortest distance matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }

    return 0;
}
