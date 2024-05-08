#include<iostream>
using namespace std;
class merge{
	public:
		int *batchersSort(int a[],int lo,int no){
			int *s;
			
	        if(no>1)
	        {
	        int mid = no / 2;
	        int m = mid;
	        int n = no - mid;
			int *u=new int[m];
			int *v=new int[n];
	        u = batchersSort(a, lo, m);
	        v = batchersSort(a, lo+mid, n);
	        s = batcher(u, v, m, n);
	        delete[] u;
	        delete[] v;
	        return s;
	    }
	     else {
	            s = new int;
	            s[0] = a[lo];
	            return s;
	        }
		}
		void compareInterchange(int &x,int &y){
			int temp;
			if(x>y){
				temp = x;
				x = y;
				y = temp;
			}
		}
		int *batcher(int u[],int v[],int m,int n){
		int i,j,*s;
		if(m==0){
			s = new int;
			s[0] = v[0];
		}
		else if(n==0){
			s[0] = u[0];
		}
		else if(m==1 && n==1){
			compareInterchange(u[0],v[0]);
			s= new int[2];
			s[0] = u[0];
			s[1] = v[0];
		}
		else{
			int x,y;
			if(m%2 == 1){
				x = m/2 + 1;
			}
			else{
				x = m/2;
			}
			if(n%2 == 1){
				y = n/2 + 1;
			}
			else{
				y = n/2;
			}
			int *ou = new int[x];
			int *ov = new int[y];
			for(i=0,j=0;i<m;i+=2,++j){
				ou[j] = u[i];
			}
			for(i=0,j=0;i<n;i+=2,++j){
				ov[j] = v[i];
			}
			int *a = batcher(ou,ov,x,y);
			delete []ou;
			delete []ov;
			int *eu = new int[m/2];
			int *ev = new int[n/2];
			for(i=1,j=0;i<m;i+=2,++j){
				eu[j] = u[i];
			}
			for(i=1,j=0;i<n;i+=2,++j){
				ev[j] = v[i];
			}
			int *b = batcher(eu,ev,m/2,n/2);
			delete []eu;
			delete []ev;
			int c;
			if((m%2==0)&&(n%2==0)){
				c = m/2 + n/2 -1;
			}
			else{
				c = m/2 + n/2;
			}
			for(i=1;i<=c;i++){
				compareInterchange(b[i-1],a[i]);
				s = new int[m+n];
				s[0] = a[0];
			}
			for(i=1,j=1;i<=c;++i){
				s[j++] = b[i-1];
				s[j++] = a[i];
			}
			if(m%2==0 && n%2==0){
				s[j++] = b[m/2 + n/2 -1];
			}
			else if(m%2==1 && n%2==1){
				s[j++] = a[m/2 + n/2 +1];
			}
			delete []a;
			delete []b;
		}
		return s;
	}
};
int main(){
	merge ob;
    int n;
    cout << "Enter The Number Of Elements In The Arrey: " << endl;
    cin >> n;
    int a[n];
    cout << "Enter The " << n << " Elements Of The Arrey: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
	int *p = ob.batchersSort(a,0,n);
	for(int i=0;i<n;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}
