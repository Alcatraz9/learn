#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct tree
{
    int data;
    tree *left, *right;
    tree(int data) : data(data), left(NULL), right(NULL){};
};

void solve(tree *root)
{
    if (root == NULL)
        return;

    queue<tree *> q;

    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        cout << root->data << " ";
        q.pop();

        if (root->left != NULL)
            q.push(root->left);
        if (root->right != NULL)
            q.push(root->right);
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
        tree *root = new tree(50);
        root->left = new tree(20);
        root->right = new tree(15);
        root->left->left = new tree(4);
        root->left->right = new tree(10);
        solve(root);
    }
}