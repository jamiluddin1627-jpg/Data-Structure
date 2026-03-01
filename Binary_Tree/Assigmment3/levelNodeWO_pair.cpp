//return all nodes of X level in a binary tree without pair in queue
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
    cin>>v;
    Node* root;
    if(v == -1) root = NULL;
    else root = new Node(v);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        int l, r;
        cin>>l>>r;
        Node* nl = NULL;
        Node* nr = NULL;
        if(l!=-1) nl = new Node(l);
        if(r!=-1) nr = new Node(r);
        cur->left = nl;
        cur->right = nr;
        if(nl) q.push(nl);
        if(nr) q.push(nr); 
    }
    return root;
}

vector<int> level_nodes(Node* root, int x)
{ 
    queue<Node*> q;
    vector<int> v;
    if(root) q.push(root);
    int level = 0;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            Node* node = q.front();
            q.pop();
            if(level == x) v.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        level++;
        if(level > x) {
            cout<<"Invalid"<<endl;
            break; 
        }
    }
    return v;
}

int main()
{
    Node* root = input_tree();
    int x;
    cin>>x;
    vector<int> v = level_nodes(root, x);
    
    if(v.empty())
    {
        cout<<"Invalid"<<endl;
        return 0;
    }
    for(int val : v)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
