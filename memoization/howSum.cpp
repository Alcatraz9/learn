#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Combinatoric
map<int, vector<int>> store;
vector<int> solve(int targetSum, vector<int> arr)
{
    if (store.find(targetSum) != store.end())
        return store[targetSum];
    if (targetSum < 0)
    {
        return vector<int>{-1};
    }
    if (targetSum == 0)
    {
        return vector<int>{0};
    }

    for (auto num : arr)
    {
        vector<int> candidates = solve(targetSum - num, arr);
        if (candidates.back() != -1)
        {
            if (candidates.back() == 0)
                candidates.pop_back();
            candidates.push_back(num);
            store[targetSum - num] = candidates;
            return candidates;
        }
    }
    store[targetSum] = {-1};
    return vector<int>{-1};
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
        // cout << "enter: ";
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        // cout << "Case #" << t << ": ";
        vector<int> res = solve(targetSum, arr);
        for (auto i : res)
            cout << i << " ";
        cout << endl;
        store.clear();
    }
}