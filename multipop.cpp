#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int ch,limit,item,arr[100],i;
    stack<int>st;
    cout<<"Enter Your Choice"<<endl;
    cout<<"\nfor exit press: 1"<<"\nfor push press: 2"<<"\nfor pop press: 3"<<"\nfor multipop press: 4"<<endl;
    while(1)
    {
        cout<<"\nenter your choice"<<endl;
        cin>>ch;
        switch (ch)
        {  
            case 1:
                    exit(1);
                    break;
            case 2:
                    cout<<"enter number :"<<endl;
                    cin>>item;
                    st.push(item);
                    break;
            case 3:
                    if (!st.empty())
                    {
                        cout << "popped " << st.top() << " from stack" << endl;
                        st.pop();
                    }
                    else
                    {
                        cout << "stack underflow" << endl;
                    }
                    break;
            case 4:
                    cout<<"Enter Number Of Element You Want To Pop"<<endl;
                    cin>>limit;
                    if (!st.empty())
                    {
                        while (limit > 0 && !st.empty())
                        {
                            cout<<st.top()<<" ";
                            st.pop();
                            limit--;
                        }
                        if (st.empty())
                        {
                            cout << "Stack Is Emptied" << endl;
                        }
                    }
                    else
                    {
                        cout << "stack underflow" << endl;
                    }
                    break;          
            default :
                    cout<<"you give a invalid choice"<<endl;
        }
    }
}
