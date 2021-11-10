#include <bits/stdc++.h>
using namespace std;
int a[1500000];
int main(){
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=max(1,i-x);j<i;j++){
			if(a[j]<a[i]) flag=1;
		}
		for(int j=min(i+1,n);j<=min(n,i+y);j++){
			if(a[j]<a[i]) flag=1;
		}
		if(!flag){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
