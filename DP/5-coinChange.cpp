#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int coinChange(vector<int> &coins, int amount)
{
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        int n;
        cin >> n;
        vector<int> coins;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            coins.push_back(temp);
        }
        int amount;
        cin >> amount;

        cout << coinChange(coins, amount) << endl;
    }
}