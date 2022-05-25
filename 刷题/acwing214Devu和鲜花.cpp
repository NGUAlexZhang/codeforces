#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
ll a[50],inv[50];
ll power(ll a,ll b){
	ll c=1;
	for(;b;b>>=1){
		if(b&1) c=c*a%MOD;
		a=a*a;a%=MOD;
	}
	return c;
}
ll C(ll n,ll m){
	if(m<0||n<0||m<n) return 0;
	m%=MOD;
	if(m==0||n==0) return 1;
	ll ans=1;
	for(int i=0;i<n;i++) ans=ans*(m-i)%MOD;
	for(int i=1;i<=n;i++){
		ans=ans*inv[i]%MOD;
	}
	return ans;
}
int main(){
	for(int i=1;i<=20;i++) inv[i]=power(i,MOD-2);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	for(int x=0;x<(1<<n);x++){
		if(x==0){
			ans=C(n-1,n+m-1);
			continue;
		}
		ll t=n+m;
		int p=0;
		for(int i=0;i<n;i++){
			if((x>>i)&1){
				p++;
				t-=a[i+1];
			}
		}
		t-=p+1;
		if(p&1){
			ans=(ans-C(n-1,t)+MOD)%MOD;
		}
		else ans=(ans+C(n-1,t))%MOD;
	}
	cout<<ans;
	return 0;
}
