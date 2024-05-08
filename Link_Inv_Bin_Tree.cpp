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

Node* link_inversion_inorder_binarytree(Node *pres)
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

Node* link_inversion_preorder_binarytree(Node *pres)
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

Node* link_inversion_postorder_binarytree(Node *pres)
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
    int ch;
    Node *root=NULL;
    root=creatnewNode(5);
    root->left=creatnewNode(7);
    root->right=creatnewNode(11);
    root->left->left=creatnewNode(2);
    root->left->right=creatnewNode(3);
    root->left->right->left=creatnewNode(12);
    root->right->right=creatnewNode(1);
    while(1)
    {
        cout<<"\nfor exit press: 0"<<"\nfor inorder: 1"<<"\nfor pre order: 2"<<"\nfor post order: 3"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 0:
                exit(1);
                break;
            case 1:
                link_inversion_inorder_binarytree(root);
                break;
            case 2:
                link_inversion_preorder_binarytree(root);
                break;
            case 3:
                link_inversion_postorder_binarytree(root);
                break;
            default :
                printf("you give a invalid choice");
                break;
        }
    }
    return 0;
}
