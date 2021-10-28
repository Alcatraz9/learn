#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int solve(int N, int K, int *A)
{

    unordered_map<int, int> s;
    int sum = 0;
    for (int j = 0; j < K; j++)
    {
        s[A[j]]++;
    }

    for (auto key : s)
    {
        sum = fmod(pow(key.first, key.second) + sum, MOD);
    }
    cout << "first" << sum << endl;
    int res = sum;

    for (int i = K; i < N; i++)
    {

        sum = fmod(sum - pow(A[i - K], s[A[i - K]]), MOD);
        sum = fmod(sum + pow(A[i - K], s[A[i - K]] - 1), MOD);

        s[A[i - K]]--;

        if (s.find(A[i]) == s.end())
        {
            sum = fmod(A[i] + sum, MOD);
        }
        else
        {
            sum = fmod(sum - pow(A[i], s[A[i]]), MOD);
            sum = fmod(sum + pow(A[i], s[A[i]] + 1), MOD);
        }
        s[A[i]]++;

        cout << "second" << sum << endl;

        res = max(sum, res);
    }

    return res;
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
        int N, K;
        int *A = (int *)malloc(sizeof(int) * (N));
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << solve(N, K, A);
    }
}