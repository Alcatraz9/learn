#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int binary_search(vector<int> a, int target)
{
    int left = 0, right = a.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            left = mid + 1;
        }
        else if (a[mid] > target)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int left_bound(vector<int> a, int target)
{
    int left = 0, right = a.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] == target)
        {
            if (a[mid - 1] == target)
                right = mid - 1;
            else
                return mid;
        }
        else if (a[mid] < target)
        {
            left = mid + 1;
        }
        else if (a[mid] > target)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int right_bound(vector<int> a, int target)
{
    int left = 0, right = a.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (a[mid] == target)
        {
            if (a[mid + 1] == target)
                left = mid + 1;
            else
                return mid;
        }
        else if (a[mid] < target)
        {
            left = mid + 1;
        }
        else if (a[mid] > target)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    int n;
    vector<int> a;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            /* code */
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        int target;
        cin >> target;
        cout << binary_search(a, target) << endl;
        cout << left_bound(a, target) << endl;
        cout << right_bound(a, target);
    }
}