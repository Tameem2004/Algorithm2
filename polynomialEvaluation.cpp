#include <iostream>

using namespace std;

int polynomialEvaluation(int x, int n,int A[])
{
    int i=n;
    int P=A[i];
    while (i>0)
    {
        P=P*x + A[--i];
    }
    return P;
}

int main()
{
    int x, n, i;
    cout << "\nEnter The Value Of x of The Polynomial P(x) : ";
    cin >> x;
    cout << "\nEnter The Highest Power Of The Polynomial : ";
    cin >> n;
    int A[n+1];
    cout<<"Enter The Coefficient Matrix : "<<endl;
    for (i = 0; i <= n; i++)
    {
        cout<<"A("<<i<<") : ";
        cin>>A[i];
    }
    cout<<"\nThe Equation: ";
    for(i=n; i>=0; i--)
    {
        if(A[i]<0)
        cout<<" "<<A[i]<<"x^"<<i;
        else if(i==n)
        cout<<A[i]<<"x^"<<i;
        else
        cout<<" + "<<A[i]<<"x^"<<i;
    }
    int result = polynomialEvaluation(x, n,A);
    cout<<"\nThe Result of P("<<x<<") With Highest Power "<<n<<" is : ";
    cout << result << endl;
    return 0;
}
