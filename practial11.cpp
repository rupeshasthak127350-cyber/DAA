
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

    int V = 5;  // Number of vertices

    const int INF = INT_MAX / 2;  // Represents infinity (no direct path)

    // Distance matrix representing the graph
    vector<vector<int>> dist = {
        {0,   2,   INF, 6,   INF},
        {2,   0,   3,   8,   5},
        {INF, 3,   0,   INF, 7},
        {6,   8,   INF, 0,   9},
        {INF, 5,   7,   9,   0}
    };

    // Floyd-Warshall algorithm starts
    // k represents the intermediate vertex
    for (int k = 0; k < V; k++) {

        // i represents the source vertex
        for (int i = 0; i < V; i++) {

            // j represents the destination vertex
            for (int j = 0; j < V; j++) {

                // Check whether the path through k is shorter
                if (dist[i][k] + dist[k][j] < dist[i][j]) {

                    // Update the shortest distance
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display the shortest distance matrix
    cout << "Shortest distance matrix:\n";

    // Loop through all rows
    for (int i = 0; i < V; i++) {

        // Loop through all columns
        for (int j = 0; j < V; j++) {

            // Check if no path exists
            if (dist[i][j] >= INF) {
                cout << "INF ";
            }
            else {
                // Print the shortest distance
                cout << dist[i][j] << "   ";
            }
        }

        cout << endl;  // Move to the next row
    }

    return 0;  // End of program
}
