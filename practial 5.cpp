#include <iostream>
#include <vector>
using namespace std;

int maximum(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int knapsack(int W, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                int take = val[i - 1] +
                           dp[i - 1][w - wt[i - 1]];

                int notTake = dp[i - 1][w];

                dp[i][w] = maximum(take, notTake);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    vector<int> weight = {10, 20, 30};
    vector<int> value = {60, 100, 120};

    int capacity = 50;
    int n = weight.size();

    cout << "0/1 Knapsack Problem" << endl;

    int answer = knapsack(capacity, weight, value, n);

    cout << "Maximum value = " << answer << endl;

    return 0;
}
