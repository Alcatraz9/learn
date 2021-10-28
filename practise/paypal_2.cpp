#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll glass2(int N, int M, string maze[1000])
{
    ll **store = 0;
    store = new ll *[N + 1];

    for (int h = 0; h < N + 1; h++)
    {
        store[h] = new ll[M + 1];

        for (int w = 0; w < M + 1; w++)
        {
            store[h][w] = INF;
        }
    }
    for (ll i = 1; i < N + 1; i++)
    {
        for (ll j = 1; j < M + 1; j++)
        {
            if (j == 1 && i == 1)
                store[1][1] = 0;

            else if (maze[i - 1][j - 1] == '.' || maze[i - 1][j - 1] == '*')
                store[i][j] = min(store[i - 1][j], store[i][j - 1]) + 1;

            else
                store[i][j] = INF;
        }
    }
    if (store[N][M] == INF)
        return -1;
    else
        return store[N][M];
}

ll glass1(int N, int M, string maze[1000])
{
    ll **store = 0;
    store = new ll *[N + 1];

    for (int h = 0; h < N + 1; h++)
    {
        store[h] = new ll[M + 1];

        for (int w = 0; w < M + 1; w++)
        {
            store[h][w] = INF;
        }
    }
    for (ll i = 1; i < N + 1; i++)
    {
        for (ll j = 1; j < M + 1; j++)
        {
            if (j == 1 && i == 1)
                store[1][1] = 0;

            else if (maze[i - 1][j - 1] == '.' || maze[i - 1][j - 1] == '#')
                store[i][j] = min(store[i - 1][j], store[i][j - 1]) + 1;

            else
                store[i][j] = INF;
        }
    }
    if (store[N][M] >= INF)
        return -1;
    else
        return store[N][M];
}

void solve(int N, int M, string maze[1000])
{
    cout << glass1(N, M, maze) << endl
         << glass2(N, M, maze);
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
        int M, N;
        cin >> N >> M;
        string maze[N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> maze[i][j];
            }
        }
        // cout << "Case #" << t  << ": ";
        solve(N, M, maze);

        // ll **res = solve(N, M, maze);
        // for (int i = 0; i < N + 1; i++)
        // {
        //     for (int j = 0; j < M + 1; j++)
        //     {
        //         cout << res[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl
        //      << res[N][M];
    }
}