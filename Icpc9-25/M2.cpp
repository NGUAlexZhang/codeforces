#include <bits/stdc++.h>
using namespace std;
int n,sgn[100],a[100],b[100],c[100];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>sgn[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int x=a[i]+b[i];
		c[i]+=x;
		if(c[i]>1){
			c[i+1]+=(sgn[i]!=sgn[i+1]?-1:1);
			c[i]%=2;
		}
		else
		if(c[i]<0){
			c[i+1]-=(sgn[i]!=sgn[i+1]?-1:1);
			c[i]=2+c[i];
		}
	}
	for(int i=1;i<n;i++) cout<<c[i]<<" ";
	cout<<c[n];
	return 0;
}
