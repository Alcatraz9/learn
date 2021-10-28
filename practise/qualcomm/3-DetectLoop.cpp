#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct node
{
    int data;
    struct node *next;
    node(int data) : data(data), next(NULL){};
};

node *solve(struct node *head)
{
    struct node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        cout << slow->data << " " << fast->data << endl;
        if (fast == slow)
            break;
    }

    cout << endl;

    if (slow != fast)
        return NULL;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        cout << slow->data << " " << fast->data << endl;
    }

    return slow;
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
        node *root = new node(50);
        root->next = new node(20);
        root->next->next = new node(15);
        root->next->next->next = new node(4);
        root->next->next->next->next = new node(10);

        root->next->next->next->next->next = root->next->next;
        cout << solve(root)->data;
    }
}