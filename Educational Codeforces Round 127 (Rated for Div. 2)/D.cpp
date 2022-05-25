#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll minn=1e11,maxn=-1,ans=0;
		for(int i=1;i<=n;i++){
			if(i!=1) ans+=abs(a[i]-a[i-1]);
			maxn=max(maxn,a[i]);
			minn=min(minn,a[i]);
		}
		if(maxn<x){
			ans+=min(2*(x-maxn),min(x-a[1],x-a[n]));
		}
		if(minn>1){
			ans+=min(2*(minn-1),min(a[1]-1,a[n]-1));
		}
		cout<<ans<<endl;
	}
	return 0;
}