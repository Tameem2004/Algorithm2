#include<iostream>
using namespace std;

void increment(int A[],int k)
{
    int i=0;
    do
    {
        A[i]=0;
        i+=1;
    }
    while(i<k&&A[i]==1);
    if(i<k)
    {
        A[i]=1;
    }
    cout<<A[i];
}
int main()
{
    int k;
    cout<<"Enter Size Of Array"<<endl;
    cin>>k;
    int A[k];
    increment(A,k);
}