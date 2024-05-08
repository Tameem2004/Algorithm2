#include <iostream> 
using namespace std; 

int *multiply(int A[], int B[], int m, int n) 
{ 
    int *prod = new int[m+n-1]; 

    for (int i = 0; i<m+n-1; i++) 
        prod[i] = 0; 

    for (int i=0; i<m; i++) 
    { 
        
        for (int j=0; j<n; j++) 
        {
            prod[i+j] += A[i]*B[j];
        } 
    } 

    return prod; 
} 

void printPoly(int poly[], int n) 
{ 
	for (int i=0; i<n; i++) 
	{ 
        if(poly[i]<0)
        cout<<" "<<poly[i]<<"x^"<<i;
        else if(i==0)
        cout<<poly[i]<<"x^"<<i;
        else
        cout<<" + "<<poly[i]<<"x^"<<i;
	} 
} 

int main() 
{ 

    int n, m, i;
    cout<<"Enter number of terms of 1st equation: ";
    cin>>n;
    cout<<"Enter number of terms of 2nd equation: ";
    cin>>m;
	int A[n], B[m]; 
    cout<<"\nEnter coefficients of 1st equation: ";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter coefficients of 2nd equation: ";
    for(i=0;i<m;i++)
    {
        cin>>B[i];
    }

	cout << "First polynomial is: "; 
	printPoly(A, n); 
	cout <<endl<< "Second polynomial is: "; 
	printPoly(B, m); 

	int *prod = multiply(A, B, n, m); 

	cout <<endl<< "Product polynomial is: "; 
	printPoly(prod, m+n-1); 

	return 0; 
}
