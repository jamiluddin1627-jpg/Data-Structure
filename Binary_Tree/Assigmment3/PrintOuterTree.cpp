#include <bits/stdc++.h>
using namespace std;

vector<int> v;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

Node* input_tree(){
    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if(l != -1){
            cur->left = new Node(l);
            q.push(cur->left);
        }

        if(r != -1){
            cur->right = new Node(r);
            q.push(cur->right);
        }
    }
    return root;
}

void left_path(Node* root)
{
    if(root == NULL) return;

    if(root->left)
        left_path(root->left);
    else if(root->right)
        left_path(root->right);

    v.push_back(root->val);
}

void right_path(Node* root)
{
    if(root == NULL) return;

    v.push_back(root->val);

    if(root->right)
        right_path(root->right);
    else if(root->left)
        right_path(root->left);
}

int main()
{
    Node* root = input_tree();
    if(root == NULL) return 0;

    if(root->left)
    {
        left_path(root);
        if(root->right)
        right_path(root->right);
    }
    else
    {
        right_path(root);
    }

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}
