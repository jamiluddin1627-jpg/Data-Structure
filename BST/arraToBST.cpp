#include <bits/stdc++.h>
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
void level_order(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        cout << cur->val << " ";

        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);
    }
}

Node* convert(int arr[], int l, int r){
    if(l > r) return NULL;

    int mid = (l + r) / 2;
    Node* root = new Node(arr[mid]);

    root->left = convert(arr, l, mid-1);
    root->right = convert(arr, mid+1, r);

    return root;
}
   
int main()
{
    int n;
    cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    Node* root = convert(arr, 0, n-1);
    level_order(root);
    
    return 0;
}
 