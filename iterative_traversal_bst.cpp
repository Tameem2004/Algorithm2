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

struct Node* insert(struct Node* root, int data){
    if(root == NULL)
	{
    root = creatnewNode(data);
    }
    else
	{
        if(data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
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
	int data,size;
    Node *root=NULL;
    cout<<"Enter size for BST"<<endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
    	cout<<"Enter data to be added: "<<endl;
    	cin>>data;
    	root = insert(root, data);
	}
    iterative_preorder(root);
    iterative_inorder(root);
    iterative_postorder(root);
    return 0;
}