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

    stack<tree *> s1;
    stack<tree *> s2;

    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            tree *temp = s1.top();
            cout << temp->data << " ";
            s1.pop();

            if (temp->right != NULL)
                s2.push(temp->right);
            if (temp->left != NULL)
                s2.push(temp->left);
        }

        while (!s2.empty())
        {
            tree *temp = s2.top();
            cout << temp->data << " ";
            s2.pop();

            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
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
        tree *root = new tree(1);
        root->left = new tree(2);
        root->right = new tree(3);
        root->left->left = new tree(7);
        root->left->right = new tree(6);
        root->right->left = new tree(5);
        root->right->right = new tree(4);
        solve(root);
    }
}