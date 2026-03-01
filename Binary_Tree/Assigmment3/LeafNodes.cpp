#include <bits/stdc++.h>
using namespace std;

vector<int> v;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node* input_tree()
{
    int val;
    cin >> val;

    Node* root;
    if(val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* nl = NULL;
        Node* nr = NULL;

        if(l != -1) nl = new Node(l);
        if(r != -1) nr = new Node(r);

        current->left = nl;
        current->right = nr;

        if(nl) q.push(nl);
        if(nr) q.push(nr);
    }

    return root;
}

void collectLeaf(Node* root)
{
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
        return;
    }

    collectLeaf(root->left);
    collectLeaf(root->right);
}

int main()
{
    Node* root = input_tree();

    collectLeaf(root);

    sort(v.begin(), v.end(), greater<int>()); // Sort in descending order

    for(int x : v)          // Print the leaf nodes in descending order where x : v is a range-based for loop that iterates through each element x in the vector v, allowing us to print each leaf node value in descending order.
        cout << x << " ";

    return 0;
}