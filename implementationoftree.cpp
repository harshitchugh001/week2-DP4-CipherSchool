#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1) // -1 is treated as NULL
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
    
}

void buildTreeFromLevelOrder(node *&root)
{
    queue<node*> q;
    cout<<"Enter data for root "<< endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<< temp->data<<endl;
        int leftData;
        cin>>leftData;
        
        if(leftData != -1){  // -1 is treated as NULL
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<< temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}

void levelOrderTraversal(node *root)  // Breadth first search
{
    // 1 NULL 3 5 NULL 7 11 17 NULL
    queue<node*> q;
    q.push(root);
    q.push(NULL);  // this is for seperator which is used to print the element in tree shape

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            // purana level complete traverse ho chuka h
            cout<<endl;
            if(!q.empty())
            {
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(node *root)
{
    if(root==NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);

}

void preorderTraversal(node *root)
{
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}

void postorderTraversal(node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root = NULL;

    // build tree by level order
    // buildTreeFromLevelOrder(root);
    // levelOrderTraversal(root);
    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"\nLevel Order Traversal of elements"<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal of element"<<endl;
    inorderTraversal(root);

    cout<<"\nPreorder Traversal of element"<<endl;
    preorderTraversal(root);

    cout<<"\nPostorder Traversal of element"<<endl;
    postorderTraversal(root);
    return 0;
}