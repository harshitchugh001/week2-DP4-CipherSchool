#include<bits/stdc++.h>
using namespace std;

class TNode
{
    public:
    int data;
    TNode* left;
    TNode* right;
};
 
TNode* newNode(int data);

TNode* sortedArrayToBST(int arr[],
                        int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid]);
 
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
 
    return root;
}

TNode* newNode(int data)
{
    TNode* node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
/* A utility function to print
preorder traversal of BST */
void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
 
// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /* Convert List to BST */
    TNode *root = sortedArrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
 
    return 0;
}