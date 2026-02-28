#include <bits/stdc++.h>

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

int sumWL(Node* root)
{
    if(root == NULL) return 0;
    
    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    
    int l = sumWL(root->left);
    int r = sumWL(root->right);
    
    return l+r+root->val;
}

int main()
{
    Node* root = input_tree();
    
    cout<<sumWL(root);

    return 0;
}
