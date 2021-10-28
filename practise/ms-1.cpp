#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int solve(vector<int> &A)
{
    int n = A.size();
    int count = 0, flag = 0;
    int store[n][n + 1];
    memset(store, 1, sizeof(store));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            store[i][j + 1 - i] = A[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    vector<int> A;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> A[i];
        // cout << "Case #" << t  << ": ";
        cout << solve(A);
    }
}