#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int matrixChainMultiplication(vector<int> p)
{
    int n = p.size() - 1;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i] * p[k + 1] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<int> p = {10, 20, 30, 40, 30};

    int result = matrixChainMultiplication(p);

    cout << "Minimum number of multiplications = "
         << result << endl;

    return 0;
}
