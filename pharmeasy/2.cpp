#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(string s)
{
    int res = -1;
    int arr[26];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'a']++;
    }

    int i;
    for (i = 0; i < s.length(); i++)
    {
        if (arr[s[i] - 'a'] == 1)
        {
            cout << i;
            break;
        }
    }

    if (i == s.length())
        cout << -1;
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
        solve("goog");
    }
}