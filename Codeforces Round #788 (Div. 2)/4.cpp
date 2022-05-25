#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll tree[750000],n,sum[750000];
ll a[150000];
int lowbit(int x){
	return x&(-x);
}
void add(ll pos,ll num){
	for(ll i=pos;i<=200000;i+=lowbit(i)){
		tree[i]+=num;
	}
}
ll ask(ll pos){
	ll res=0;
	while(pos>0){
		res+=tree[pos];
		pos-=lowbit(pos);
	}
	return res;
}
bool check(ll x){
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]>=x?1:-1);
	}
	ll ans=0;
	for(int i=0;i<=n;i++){ 
		ans+=ask(sum[i]+1e5);
		add(sum[i]+1e5,1);
	}
	return ans>=(n+1)*n/4;
}
int main(){
	cin>>n;
	ll l=1,r=0;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		r=max(r,a[i]);	
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld",l-1);
	return 0;
}
