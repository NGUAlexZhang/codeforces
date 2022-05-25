#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==3&&a[2]%2){
			puts("-1");continue;
		}
		bool flag=1;
		for(int i=2;i<n;i++)
			if(a[i]!=1) flag=0;
		if(flag){
			puts("-1");continue;
		}
		ll ans=0;
		for(int i=2;i<n;i++){
			ans+=a[i]/2;
			ans+=a[i]%2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
