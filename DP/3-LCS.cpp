// Given str1 and str2, find out the length of the longest common subsequence.

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// int solve(string s1, string s2, int i, int j)
// {
//     if (i == -1 || j == -1)
//         return 0;

//     if (s1[i] == s2[j])
//     {
//         return solve(s1, s2, i - 1, j - 1) + 1;
//     }
//     else
//     {
//         return max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
//     }
// }

int solve(string s1, string s2)
{
    int n = s2.size(), m = s1.size();
    vector<vector<int>> store(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s2[i - 1] == s1[j - 1])
            {
                store[i][j] = store[i - 1][j - 1] + 1;
            }
            else
            {
                store[i][j] = max(store[i - 1][j], store[i][j - 1]);
            }
        }
    }
    return store[n][m];
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
        string s1, s2;
        cin >> s1 >> s2;
        // cout << solve(s1, s2, s1.length() - 1, s2.length() - 1);
        cout << solve(s1, s2);
    }
}