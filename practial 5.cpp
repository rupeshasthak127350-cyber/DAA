
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum of two numbers
int maximum(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int> wt, vector<int> val, int n)
{
    // Create a DP table and initialize all values to 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Loop through all items
    for (int i = 1; i <= n; i++)
    {
        // Loop through all possible capacities
        for (int w = 1; w <= W; w++)
        {
            // Check if the current item can fit in the bag
            if (wt[i - 1] <= w)
            {
                // Calculate value by taking the item
                int take = val[i - 1] +
                           dp[i - 1][w - wt[i - 1]];

                // Calculate value without taking the item
                int notTake = dp[i - 1][w];

                // Store the maximum of both choices
                dp[i][w] = maximum(take, notTake);
            }
            else
            {
                // If item cannot fit, do not take it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value
    return dp[n][W];
}

// Main function
int main()
{
    // Define weights of items
    vector<int> weight = {10, 20, 30};

    // Define values of items
    vector<int> value = {60, 100, 120};

    // Set maximum capacity of the bag
    int capacity = 50;

    // Calculate number of items
    int n = weight.size();

    // Display the problem name
    cout << "0/1 Knapsack Problem" << endl;

    // Call knapsack function
    int answer = knapsack(capacity, weight, value, n);

    // Display maximum value
    cout << "Maximum value = " << answer << endl;

    return 0;
}
