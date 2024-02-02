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

void visit_pres(int data) {
    cout << data << " ";
}

int link_inversion_inorder_binarytree(Node *pres)
{
    cout<<"Link Inversion Inorder:-"<<endl;
    Node* prev,*tmp;
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
            }
            if(prev==NULL&&pres->right==NULL)
            {
                flag=2;
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

int link_inversion_preorder_binarytree(Node *pres)
{
    cout<<"Link Inversion Preorder:-"<<endl;
    Node* prev,*tmp;
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
                if(prev==NULL&&pres->right==NULL)
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
int link_inversion_postorder_binarytree(Node *pres)
{
    cout<<"Link Inversion Postorder:-"<<endl;
    Node* prev,*tmp;
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
    Node *pres=NULL;
    pres=creatnewNode(5);
    pres->left=creatnewNode(7);
    pres->right=creatnewNode(11);
    pres->left->left=creatnewNode(2);
    pres->left->right=creatnewNode(3);
    pres->left->right->left=creatnewNode(12);
    pres->right->right=creatnewNode(1);
    link_inversion_inorder_binarytree(pres);
    link_inversion_preorder_binarytree(pres);
    link_inversion_postorder_binarytree(pres);
    return 0;
}
