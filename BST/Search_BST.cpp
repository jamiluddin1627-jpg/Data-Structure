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

bool binary_search(Node* root, int x){
    if(root == NULL) return false;

    if(root->val == x){
        return true;
    }

    if(x < root->val) return binary_search(root->left, x);
    else return binary_search(root->right, x);
}
   
int main()
{
    Node* root = input_tree();
    if(root == NULL) return 0;

    int x;
    cin >> x;
    if(binary_search(root, x)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    
    return 0;
}
