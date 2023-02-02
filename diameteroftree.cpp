#include<bits/stdc++.h>
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


pair<int, int> diameter(TreeNode<int> *root)  // pair<diameter, height>
{
    if(root==NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameter(root->left);  // this will calculate the diameter of left subtree
    pair<int, int> right = diameter(root->right);// this will calculate the diameter of right subtree

    int op1 = left.first;   // maximum diameter can exist in left subtree
    int op2 = right.first;  // maximum diameter can exist in right subtree
    int op3 = left.second + right.second + 1;  // maximum diameter can be the combination of left subtree and right subtree
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));  // checking which diameter is maximum and storing it in ans.first which is showing diameter
    ans.second = max(left.second, right.second) + 1; // storing the height of the tree
    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans = diameter(root).first;
    return ans - 1;
}