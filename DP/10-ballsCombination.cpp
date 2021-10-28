// There are ‘R’ balls of type R, ‘G’ balls of type G and ‘T’ balls of type T. Using the balls we want to create a straight line such that no two balls of same type are adjacent

#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Recursion
int util(int R, int G, int T, char ends_with)
{
    if (R < 0 || G < 0 || T < 0)
        return 0;

    if ((R == 1 && G == 0 && T == 0 && ends_with == 'R') || (R == 0 && G == 1 && T == 0 && ends_with == 'G') || (R == 0 && G == 0 && T == 1 && ends_with == 'T'))
        return 1;

    if (ends_with == 'R')
        return util(R - 1, G, T, 'G') + util(R - 1, G, T, 'T');
    if (ends_with == 'G')
        return util(R, G - 1, T, 'R') + util(R, G - 1, T, 'T');
    if (ends_with == 'T')
        return util(R, G, T - 1, 'R') + util(R, G, T - 1, 'G');
}

int solve(int R, int G, int T)
{
    return util(R, G, T, 'R') + util(R, G, T, 'G') + util(R, G, T, 'T');
}

int solve(int R, int G, int T)
{
    return util(R, G, T, 'R') + util(R, G, T, 'G') + util(R, G, T, 'T');
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
        cout << solve(1, 1, 0);
    }
}