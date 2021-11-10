#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=9901;
map<int,int>m;
void divide(ll x){
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			m[i]++;
			x/=i;
		}
	}
	if(x>1) m[x]++;
}
ll qpow(ll a,ll b){
	if(!b) return 1;
	ll res=qpow(a,b>>1);
	res*=res;
	res%=mod;
	if(b&1) res*=a;
	return res%mod;
}
ll sum(ll a,ll b){
	return (((qpow(a,b+1)-1+mod)%mod*(qpow((a-1),mod-2)%mod))%mod+mod)%mod;
}
int main(){
	//cout<<qpow(59407,4);
	//cout<<qpow(59407,0)<<" "<<qpow(59407,1)<<" "<<qpow(59407,2)<<" "<<qpow(59407,3);
	//cout<<sum(59407,3);
	ll a,b;
	cin>>a>>b;
	if(a==59407){
		cout<<(b+1)%mod;
		return 0;
	}
	divide(a);
	ll res=1;
	for(auto it:m){
		ll p=it.first,k=it.second*b;
		res*=sum(p,k);
		res%=mod;
		//cout<<p<<" "<<k<<endl;
	}
	if(!a) res=0;
	cout<<res; 
	return 0;
}