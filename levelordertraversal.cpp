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




int main()
{
    node *root = NULL;

    
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Level order Traversal of element"<<endl;
    levelOrderTraversal(root);

    return 0;
}