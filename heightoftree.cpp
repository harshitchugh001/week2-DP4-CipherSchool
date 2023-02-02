#include <bits/stdc++.h> 
using namespace std;


template <typename T>
class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};


int height(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left1 = height(root->left);  // it will give me the height of left subtree
    int right1 = height(root->right); // it will give me the height of right subtree

    int ans = max(left1, right1) + 1;
    return ans;
}

int maxDepth(TreeNode<int> *root) {
    // Write your code here.
    return height(root)-1;
}