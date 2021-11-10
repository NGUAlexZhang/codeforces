#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod= 998244353;
ll jie[2000005];
ll qpow(ll a,ll b){
    ll ans=1,base=a;
    while(b){
        if(b & 1){
        	ans=ans*base;
        	ans%=mod;
        }
        base=base*base;
        base%=mod;
        b = b >> 1;
    }
    return ans;
}
ll cal(ll n,ll m){
	return jie[n]*qpow(jie[m],mod-2)%mod;
}
int main(){
	int T;
	jie[0]=1;
	for(int i=1;i<=205005;i++) jie[i]=jie[i-1]*i,jie[i]%=mod;
	cin>>T;
	while(T--){
		map<ll,ll> m;
		vector<ll>all;
		int n;
		cin>>n;
		ll sum=0;
		for(int i=1;i<=n;i++){
			ll x;
			cin>>x;
			if(!m[x])
				all.push_back(x);
			m[x]++;	
		}
		sort(all.begin(),all.end());
		int len=all.size();
		ll fir=all[len-1];
		if(len==1||m[fir]>1){
			cout<<jie[n]<<endl;
			continue;
		}
		ll sec=all[len-2];
		for(int i=1;i<len-1;i++) sum+=all[i];
		if(m[fir]==1&&fir-sec!=1){
			cout<<0<<endl;
			continue;
		}
		ll res=jie[m[fir]]*jie[m[sec]];
		res%=mod;
		res*=cal(n,m[fir]+m[sec]);
		res%=mod;
		cout<<((jie[n]-res)%mod+mod)%mod<<endl;
	}
	return 0;
}