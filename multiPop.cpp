#include <bits/stdc++.h>

using namespace std;
#define MAX 10

class multi
{
private:
    stack<int>s;
    int n;
public:
    void setTop(){
        cout<<"Enter The Element You Want To Push: "<<endl;
        cin>>n;
        s.push(n);
        return;
    }
    void getTop(){
        if(s.empty()){
            cout<<"Sorry! No More Elements in The Stack"<<endl;
            return;
        }
        cout<<"The Top Element Is: "<<s.top()<<endl;
        return;
    }
    void spop(){
        if(s.empty()){
            cout<<"Sorry! No More Elements in The Stack"<<endl;
            return;
        }
        cout<<s.top()<<"\t";
        s.pop();
        return;
    }
    void multiPop(int i){
        for (int j = 0; j < i; j++)
        {
            if(s.empty()){
                cout<<"Sorry! No More Elements in The Stack"<<endl;
                return;
            }
            else{
                if(j==0)
                    cout<<"The "<<i<<" Elements Poped Are: "<<endl;
                spop();
            }
        }
        cout<<endl;
        return;
    }
};

int main()
{
    multi A;
    int ch;
    int i;
    while (1)
    {
        cout<<"What You Want To Do?:\n1. Push Data\t2. Pop Once\n3. Multiple Pop\t4. See The Top\n\t5.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            A.setTop();
            break;
        case 2:
            A.spop();
            break;
        case 3:
            cout<<"Enter The Number Of Times You Want To Pop: "<<endl;
            cin>>i;
            A.multiPop(i);
            break;
        case 4:
            A.getTop();
            break;
        case 5:
            exit(1);
            break;
        default:
            return 0;
        }
    }
    return 0;
}
