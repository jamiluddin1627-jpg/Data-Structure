#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int mx = 0;

int maxHeight(TreeNode<int> *root)
{
    if(root == NULL) return 0;

    int l = maxHeight(root->left);
    int r = maxHeight(root->right);

    mx = max(mx, l + r);   // diameter in edges

    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    mx = 0;
    maxHeight(root);
    return mx;
}

// Build Tree using Level Order Input
TreeNode<int>* buildTree()
{
    int data;
    cin >> data;

    if(data == -1) return NULL;

    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* current = q.front();
        q.pop();

        int leftData, rightData;
        cin >> leftData;

        if(leftData != -1)
        {
            current->left = new TreeNode<int>(leftData);
            q.push(current->left);
        }

        cin >> rightData;

        if(rightData != -1)
        {
            current->right = new TreeNode<int>(rightData);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    TreeNode<int>* root = buildTree();

    cout << diameterOfBinaryTree(root);

    return 0;
}