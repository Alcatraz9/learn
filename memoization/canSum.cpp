#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// decision

map<int, bool> store;
bool solve(int targetSum, vector<int> arr)
{
    if (store.find(targetSum) != store.end())
        return store[targetSum];
    if (targetSum < 0)
        return false;
    if (targetSum == 0)
        return true;

    for (auto num : arr)
    {
        if (solve(targetSum - num, arr) == true)
        {
            store[targetSum] = true;
            return true;
        }
    }
    store[targetSum] = false;
    return false;
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
        int targetSum, n;
        vector<int> arr;
        cin >> targetSum >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        // cout << "Case #" << t  << ": ";
        cout << solve(targetSum, arr);
        store.clear();
    }
}