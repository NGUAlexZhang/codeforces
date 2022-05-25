#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[250000],sum[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		ll x;
		cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		int index=-1;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			if(sum[i]>x&&index==-1) index=i-1;
		}
		if(index==-1) index=n;
		//cout<<index<<endl;
		ll ans=0,las=0;
		for(int i=index;i>=1;i--){
			//sum[i]+i*(d-1)<=x
			ll d=(x-sum[i])/i+1;
			ans+=d;
		}
		cout<<ans<<endl;
	}
	return 0;
}
