#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    int tag;
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


Node* insert(Node* root, int data){
    if(root == NULL){
        root = creatnewNode(data);
        }
    else{
        if(data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}

void visit_pres(int data) {
    cout << data << " ";
}

Node* link_inversion_inorder_bst(Node *pres)
{
    cout<<"Link Inversion Inorder:-"<<endl;
    Node *prev,*tmp;
    prev=NULL;
    int flag=0;
    if(pres==NULL)
    {
        return 0;
    }
    do
    {
        if(pres->left!=NULL&&flag==0)
        {
            tmp=pres->left;
            pres->left=prev;
            pres->tag=0;
            prev=pres;
            pres=tmp;
            flag=0;
        }
        else{
            if(flag!=2)
            {
                visit_pres(pres->data);
                if(prev==NULL&&pres->right==NULL)
                {
                    flag=2;
                }
            }
            if(pres->right!=NULL&&flag!=2)
            {
                tmp=pres->right;
                pres->right=prev;
                pres->tag=1;
                prev=pres;
                pres=tmp;
                flag=0;
            }
            else if(prev!=NULL&&prev->tag==0)
            {
                tmp=prev->left;
                prev->left=pres;
                pres=prev;
                prev=tmp;
                flag=1;
            }
            else if(prev!=NULL&&prev->tag==1)
            {
                tmp=prev->right;
                prev->right=pres;
                pres=prev;
                prev=tmp;
                flag=2;
            }
        }
    }
    while(prev!=NULL||flag!=2);
    cout<<endl;
}

Node* link_inversion_preorder_bst(Node *pres)
{
    cout<<"Link Inversion Preorder:-"<<endl;
    Node *prev,*tmp;
    prev=NULL;
    int flag=0; 
    if(pres==NULL)
    {
        return 0;
    }
    do
    {
        if(flag==0)
        {
            visit_pres(pres->data);
        }
        if(pres->left!=NULL&&flag==0)
        {
            tmp=pres->left;
            pres->left=prev;
            pres->tag=0;
            prev=pres;
            pres=tmp;
            flag=0;
        }
        else
        {
            if(pres->right!=NULL&&flag!=2)
            {
                tmp=pres->right;
                pres->right=prev;
                pres->tag=1;
                prev=pres;
                pres=tmp;
                flag=0;
            }
            else if(prev!=NULL&&prev->tag==0)
            {
                if(prev==NULL&&pres->left==NULL&&pres->right==NULL)
                {
                    flag=2;
                }
                else
                {
                    flag=1;
                }
                tmp=prev->left;
                prev->left=pres;
                pres=prev;
                prev=tmp;
            }
            else if(prev!=NULL&&prev->tag==1)
            {
                tmp=prev->right;
                prev->right=pres;
                pres=prev;
                prev=tmp;
                flag=2;
            }
        }
    }
    while(prev!=NULL||flag!=2);
    cout<<endl;
}

Node* link_inversion_postorder_bst(Node *pres)
{
    cout<<"Link Inversion Postorder:-"<<endl;
    Node *prev,*tmp;
    prev=NULL;
    int flag=0;
    if(pres==NULL)
    {
        return 0;
    }
    do
    {
        if(pres->left!=NULL&&flag==0)
        {
            tmp=pres->left;
            pres->left=prev;
            pres->tag=0;
            prev=pres;
            pres=tmp;
            flag=0;
        }
        else
        {
            if(pres->right!=NULL&&flag!=2)
            {
                tmp=pres->right;
                pres->right=prev;
                pres->tag=1;
                prev=pres;
                pres=tmp;
                flag=0;
            }
            else if(prev!=NULL&&prev->tag==0)
            {
                tmp=prev->left;
                prev->left=pres;
                pres=prev;
                prev=tmp;
                flag=1;
            }
            else if(prev!=NULL&&prev->tag==1)
            {
                tmp=prev->right;
                prev->right=pres;
                pres=prev;
                prev=tmp;
                flag=2;
            }
        }
        if(flag==2||(pres->right==NULL&&flag==1)||(pres->left==NULL&&pres->right==NULL&&flag==0))
        {
            visit_pres(pres->data);
            flag=2;
        }
    }
    while(prev!=NULL||flag!=2);
    cout<<endl;
}

int main()
{
	int size,data;
    Node *root=NULL;
    cout<<"Enter size for BST"<<endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
    	cout<<"Enter data to be added: "<<endl;
    	cin>>data;
    	root = insert(root, data);
	}
    link_inversion_inorder_bst(root);
    link_inversion_preorder_bst(root);
    link_inversion_postorder_bst(root);
    return 0;
}
