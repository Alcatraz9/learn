#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(vector<int> arr, int start, int end)
{
    int flag = 1;
    for (auto i : arr)
    {
        if (abs(i) <= end && abs(i) >= start)
        {
            flag = 0;
            cout << i << " ";
        }
    }

    if (flag)
    {
        cout << "-1";
    }
}

int main()
{

    int n, start, end;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> start >> end;
    solve(arr, start, end);
}