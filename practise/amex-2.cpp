#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr)
{
    int size = arr.size();

    // distance is max if first and last element are different
    if (arr[0] != arr[size - 1])
        return (size - 1);

    // traverse array from back for fixed first element
    int i = size - 1;
    while (i > 0)
    {

        // different element found
        if (arr[i] != arr[0])
        {
            break;
        }

        i--;
    }

    // distance from first element
    int dist1 = i;

    // traverse array from front for fixed flast element
    i = 0;
    while (i < size - 1)
    {

        // different element found
        if (arr[i] != arr[size - 1])
            break;
        i++;
    }

    // To store the distance from the last element
    int dist2;
    // all elements are equal
    if (i == size - 1)
    {
        dist2 = 0;
    }
    else
    {
        dist2 = size - 1 - i;
    }

    return max(dist1, dist2);
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
        for (int t = 1; t <= tc; t++)
        {
            vector<int> arr;
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int temp;
                cin >> temp;
                arr.push_back(temp);
            }
            cout << solve(arr);
        }
    }
}