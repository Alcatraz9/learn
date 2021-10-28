#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *TrimBinarySearchTree(struct TreeNode *root, int minValue, int maxValue)
{
    if (root == NULL)
        return NULL;

    root->left = TrimBinarySearchTree(root->left, minValue, maxValue);
    root->right = TrimBinarySearchTree(root->right, minValue, maxValue);

    if (root->data < minValue)
    {
        TreeNode *rChild = root->right;
        delete root;
        return rChild;
    }

    if (root->data > maxValue)
    {
        TreeNode *lChild = root->left;
        delete root;
        return lChild;
    }

    return root;
}

TreeNode *newTreeNode(int num)
{
    TreeNode *temp = new TreeNode;
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a given data to BST
TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
        return newTreeNode(data);
    if (root->data > data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Utility function to traverse the binary tree after conversion
void inorderTraversal(TreeNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
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
        TreeNode *root = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            root = insert(root, temp);
        }
        int minValue, maxValue;
        cin >> minValue >> maxValue;

        root = TrimBinarySearchTree(root, minValue, maxValue);

        inorderTraversal(root);
    }
}