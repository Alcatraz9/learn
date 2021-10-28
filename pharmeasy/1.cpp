#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(vector<int> arr, int sum)
{
    sort(arr.begin(), arr.end());
    int i, l, r;
    int flag = 0;
    for (i = 0; i < arr.size() - 2; i++)
    {
        l = i + 1;
        r = arr.size() - 1;

        while (sum >= arr[i] + arr[l] + arr[r])
        {
            l = (l + r) / 2;
            if (l == r)
                break;
            if (sum == arr[i] + arr[l] + arr[r])
            {
                flag = 1;
                cout << " " << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                break;
            }
        }
        if (flag)
            break;
    }
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
        vector<int> arr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        int sum;
        cin >> sum;
        solve(arr, sum);
    }
}