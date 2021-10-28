#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A)
{
    int size = A.size();
    if (size == 0)
    {
        return 0;
    }

    int l = 0, r = size - 1;

    // get l to first point of ambiguity from left
    while (l < size - 1 && A[l] <= A[l + 1])
    {
        l++;
    }

    // already in non decreasing order
    if (l == A.size() - 1)
    {
        // no changes reqd
        return 0;
    }

    // get r to first point of ambiguity from right
    while (r > l && A[r - 1] <= A[r])
    {
        --r;
    }

    // delete either all elements on left of r or all elements on right of l
    // gives max possible valid answer
    int ans = min(size - l - 1, r);

    // sliding window to check if we can minimise deletions
    int i = 0;
    int j = r;
    while (i <= l && j < size)
    {
        if (A[j] >= A[i])
        {
            ans = min(ans, j - i - 1);
            ++i;
        }
        // point of ambiguity
        else
            ++j;
    }
    return ans;
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
        vector<int> A;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            A.push_back(temp);
        }
        cout << solve(A);
    }
}