#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[100];
int main(){
	ans[0]=1;
	for(int i=1;i<=60;i++) ans[i]=ans[i-1]*2;
	int T;
	cin>>T;
	while(T--){
		ll m,n;
		cin>>m>>n;
		if(m==1){
			if(n==0) cout<<1<<endl;
			else cout<<2<<endl;
			continue;
		}
		if(n==0)
			cout<<ans[m]<<endl;
		else cout<<ans[m]-1<<endl;
	}
	return 0;
}
