// https://labuladong.gitbook.io/algo-en/i.-dynamic-programming/editdistance

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

map<pair<int, int>, int> memo_store;

int memo(string s1, string s2, int i, int j)
{
    if (memo_store.find(make_pair(i, j)) != memo_store.end())
        return memo_store[make_pair(i, j)];
    if (i == -1)
        return j + 1;

    if (j == -1)
        return i + 1;

    if (s1[i] == s2[j])
    {
        memo_store[make_pair(i, j)] = memo(s1, s2, i - 1, j - 1);
    }
    else
    {
        memo_store[make_pair(i, j)] = min(
            min(memo(s1, s2, i, j - 1) + 1, memo(s1, s2, i - 1, j) + 1),
            memo(s1, s2, i - 1, j - 1) + 1);
    }

    return memo_store[make_pair(i, j)];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    string s1, s2;
    for (int t = 1; t <= tc; t++)
    {
        cin >> s1 >> s2;
        // cout << "Case #" << t  << ": ";
        cout << "Memo: " << memo(s1, s2, s1.length() - 1, s2.length() - 1);
        memo_store.clear();
    }
}