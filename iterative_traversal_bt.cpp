#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

Node* creatnewNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void iterative_preorder(Node* root)
{
    stack<Node*>st;
    cout<<"Iterative Preorder:-"<<endl;
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        if(root->right!=NULL)
        {
            st.push(root->right);
        }
        if(root->left!=NULL)
        {
            root=root->left;
        }
        else
        {
            if (!st.empty()) 
            {
                root = st.top();
                st.pop();
            } else 
            {
                break;
            }
        }
    }
}

void iterative_inorder(Node* root)
{
    stack<Node*>st;
    cout<<"\nIterative Inorder:-"<<endl;
    do
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        if(!st.empty())
        {
            root=st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->right;
        }
        else
        {
            break;
        }
    }
    while(1);
}   

void iterative_postorder(Node* root)
{
    stack<Node*>st;
    cout<<"\nIterative Postorder:-"<<endl;
    do
    {
        while(root!=NULL)
        {
            if(root->right!=NULL)
            {
                st.push(root->right);
            }
            st.push(root);
            root=root->left;  
        }
        if(!st.empty())
        {
            root=st.top();
            st.pop();
            if(root->right != NULL && !st.empty() && root->right == st.top())
            {
                st.pop();
                st.push(root);
                root=root->right;
            }
            else
            {
                cout<<root->data<<" ";
                root=NULL;
            }
        }
    }
    while(!st.empty());
}

int main()
{
    Node *root=NULL;
    root=creatnewNode(5);
    root->left=creatnewNode(7);
    root->right=creatnewNode(11);
    root->left->left=creatnewNode(2);
    root->left->right=creatnewNode(3);
    root->left->right->left=creatnewNode(12);
    root->right->right=creatnewNode(1);
    iterative_preorder(root);
    iterative_inorder(root);
    iterative_postorder(root);
    return 0;
}
