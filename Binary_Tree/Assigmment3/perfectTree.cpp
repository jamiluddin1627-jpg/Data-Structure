#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    
};

Node* input_tree()
{
    int v;
    cin>> v;
    Node* root;
    if(v == -1) root = NULL;
    else root = new Node(v);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();
        
        int l, r;
        cin>>l>>r;
        Node* nL = NULL;
        Node* nR = NULL;
        if(l != -1) nL = new Node(l);
        if(r != -1) nR = new Node(r);
        
        current->left = nL;
        current->right = nR;
        
        if(nL) q.push(nL);
        if(nR) q.push(nR);
    }
    return root;
    
}

int countNodes(Node* root)
{
    if(root == NULL) return 0;
    
    int l = countNodes(root->left);
    int r = countNodes(root->right);
    
    return l + r + 1;
}

int maxDepth(Node* root)
{
    if(root == NULL) return 0;
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    
    return max(l, r) + 1;
}

int main()
{
    Node* root = input_tree();
    
    int total_nodes = countNodes(root);
    int max_depth = maxDepth(root);
    
    if(total_nodes == pow(2, max_depth) - 1) cout<<"Yes";
    else cout<<"No";
    return 0;
}