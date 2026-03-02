#include <bits/stdc++.h>
using namespace std;

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

void level_order(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        cout << cur->val << " ";

        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);
    }
}

void insert_in_BST(Node *&root, int x){
    if(root == NULL){
        root = new Node(x);
        return;
    }

    if(x < root->val) insert_in_BST(root->left, x);
    else insert_in_BST(root->right, x);
}
   
int main()
{
    Node* root = input_tree();
    if(root == NULL) return 0;
    int x;
    cin >> x;
    insert_in_BST(root, x);
    level_order(root);
    
    return 0;
}
 