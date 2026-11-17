
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n = 4;  // Number of cities

    // Cost matrix representing distance between cities
    int cost[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> cities;

    // Store all cities except starting city 0
    for (int i = 1; i < n; i++)
    {
        cities.push_back(i);
    }

    int minCost = INT_MAX;  // Store minimum cost
    vector<int> bestPath;  // Store best route

    // Generate all possible city arrangements
    do
    {
        int currentCost = 0;
        int k = 0;  // Start from city 0

        // Calculate cost of current route
        for (int i = 0; i < cities.size(); i++)
        {
            currentCost += cost[k][cities[i]];
            k = cities[i];
        }

        // Add cost to return to starting city
        currentCost += cost[k][0];

        // Check if current route has minimum cost
        if (currentCost < minCost)
        {
            minCost = currentCost;
            bestPath = cities;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    // Display minimum travelling cost
    cout << "Minimum Cost: " << minCost << endl;

    // Display the best travelling path
    cout << "Best Path: 0 ";

    for (int i = 0; i < bestPath.size(); i++)
    {
        cout << "-> " << bestPath[i];
    }

    cout << " -> 0" << endl;

    return 0;  // End of program
}
