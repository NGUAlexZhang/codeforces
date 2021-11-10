#include <bits/stdc++.h>
using namespace std;
int a[15000];
int main(){
	map<int,int>m[15000];
	int n,p,h,q;
	cin>>n>>p>>h>>q;
	for(int i=1;i<=q;i++){
		int A,B;
		cin>>A>>B;
		if(A>B) swap(A,B);
		if(m[A][B]||A>n||B>n||A==B) continue;
		m[A][B]=1;
		a[A+1]--,a[B]++;
	}
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	int tmp=h-a[p];
	for(int i=1;i<=n;i++) a[i]+=tmp;
	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}
