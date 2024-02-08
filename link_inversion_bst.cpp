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

struct Node* insert(struct Node* pres, int data){
    if(pres == NULL)
	{
    pres = creatnewNode(data);
    }
    else
	{
        if(data < pres->data)
            pres->left = insert(pres->left, data);
        else
            pres->right = insert(pres->right, data);
    }
    return pres;
}

void visit_pres(int data) {
    cout << data << " ";
}

int link_inversion_inorder_bst(Node *pres)
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

int link_inversion_preorder_bst(Node *pres)
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
int link_inversion_postorder_bst(Node *pres)
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
	int size,data;
    Node *pres=NULL;
    cout<<"Enter size for BST"<<endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
    	cout<<"Enter data to be added: "<<endl;
    	cin>>data;
    	pres = insert(pres, data);
	}
    link_inversion_inorder_bst(pres);
    link_inversion_preorder_bst(pres);
    link_inversion_postorder_bst(pres);
    return 0;
}