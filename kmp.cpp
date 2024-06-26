 //PROGRAM TO IMPLEMENT KMP

#include<iostream>
using namespace std;

void Compute_kmp(string pattern, string text);
void Compute_lps(string pattern, int lps[], int m);
int main()
{
    string text, pattern;
    cout<<"Enter the text: ";
    cin>>text;
    cout<<"Enter pattern: ";
    cin>>pattern;
    Compute_kmp(pattern, text);
    return 0;
}
//to find the pattern in the text
void Compute_kmp(string pattern, string text)
{
    int n, m, i, j, flag;
    n = text.length(), m = pattern.length();
    int* lps = new int[m];
    i=j=0;
    lps[0] = 0;
    Compute_lps(pattern, lps, m);
    flag=0;
    while(i<n)
    {
        if(text[i] == pattern[j])
        {
            i+=1, j+=1;
        }
        else if(j!=0)
        {
            j = lps[j-1];
        }
        else
        {
            i+=1;
        }
        if(j == m)
        {
            cout<<"\nFound pattern '"<<pattern<<"' at position "<<(i - j + 1);
            flag=1;
            j = 0;
        }
    }
    if(flag==0)
    {
        cout<<"\nPattern Not Found";
    }
    delete[] lps;
}
//to find any repeatation in pattern
void Compute_lps(string pattern, int lps[], int m)
{
    int i=1, len=0;
    while(i<m)
    {
        if(pattern[i]==pattern[len])
        {
            lps[i] = len+1;
            i+=1, len+=1;
        }
        else if(len!=0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i] = 0;
            i+=1;
        }
    }
}