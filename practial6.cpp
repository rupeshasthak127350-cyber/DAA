
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Function for Matrix Chain Multiplication
int matrixChainMultiplication(vector<int> p)
{
    int n = p.size() - 1;

    // Create DP table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Check different chain lengths
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;

            // Initialize minimum cost
            dp[i][j] = INT_MAX;

            // Try all possible splits
            for (int k = i; k < j; k++)
            {
                // Calculate multiplication cost
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i] * p[k + 1] * p[j];

                // Update minimum cost
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

// Main function
int main()
{
    vector<int> p = {10, 20, 30, 40, 30};

    // Call function
    int result = matrixChainMultiplication(p);

    // Display result
    cout << "Minimum number of multiplications = "
         << result << endl;

    return 0;
}
