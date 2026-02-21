#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree(){
    int val;
    cin>>val;
    Node *root;
    if(val == -1) root = NULL; // if the first value is -1 then the tree is empty and root will be NULL
    else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        int l, r;
        cin>>l>>r;
        Node *newLeft = NULL;
        Node *newRight = NULL;
        if(l != -1) newLeft = new Node(l);
        if(r != -1) newRight = new Node(r);
        // connecting current with newLeft and newRight
        current->left = newLeft;
        current->right = newRight;
        // pushing newLeft and newRight in the queue if they are not NULL
        if(newLeft) q.push(newLeft);
        if(newRight) q.push(newRight); 
    }
    return root;
}

void level_order(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<current->val<<" ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}
int main()
{
    Node* root = input_tree();
    level_order(root);
    return 0;
}