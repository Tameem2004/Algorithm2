#include<iostream>
#include <vector>
using namespace std;

void increment(vector<int>& A, int k) {
    int i = 0;
    for (int j =k-1; j >=0; j--) {
        cout << A[j];
    }
    cout<<endl;
    while (i < k && A[i] == 1)
    {
        A[i] = 0;
        i += 1;
    }
    if (i < k) {
        A[i] = 1;
    }
}

int main() {
    int k;

    cout << "Enter Size Of Array" << endl;
    cin >> k;
    vector<int> A(k, 0);
    for (int count = 0; count < (1 << k); count++) {
        increment(A,k);
    }
}
