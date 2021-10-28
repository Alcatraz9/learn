#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll store[MAX_N + 1][2];

int solve(int n)
{
    store[1][0] = 2;
    store[1][1] = 3;
    store[2][0] = 3;
    store[2][1] = 4;
    for (int i = 3; i <= n; i++)
    {
        store[i][0] = fmod(2 * store[i - 1][0] + 2 * store[i - 2][1], MOD);
        store[i][1] = fmod(3 * store[i - 2][0] + store[i - 1][1], MOD);
    }

    return store[n][1];
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
        int n;
        cin >> n;
        // cout << "Case #" << t  << ": ";
        cout << solve(n);
    }
}