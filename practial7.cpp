#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> coins;
vector<int> memo;

// Top-down recursive approach with memoization (instead of bottom-up iteration)
int solve(int remaining) {
    if (remaining == 0)
        return 0;
    if (remaining < 0)
        return INT_MAX;
    if (memo[remaining] != -1)
        return memo[remaining];

    int best = INT_MAX;

    for (int c : coins) {
        int sub = solve(remaining - c);
        if (sub != INT_MAX) {
            best = min(best, sub + 1);
        }
    }

    memo[remaining] = best;
    return best;
}

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    coins.resize(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    memo.assign(amount + 1, -1);

    int result = solve(amount);

    if (result == INT_MAX)
        cout << "Amount cannot be formed";
    else
        cout << "Minimum number of coins: " << result;

    return 0;
}
