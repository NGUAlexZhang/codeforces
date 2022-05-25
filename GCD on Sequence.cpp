#include <bits/stdc++.h>
#define ll long long
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
const int MAX=1e5+5;
ll n,loc[MAX],mx[MAX<<2],sum[MAX<<2],lzy[MAX<<2];
void push_up(ll rt){
	mx[rt]=max(mx[lson],mx[rson]);
	sum[rt]=sum[lson]+sum[rson];
}
void push_down(ll rt,ll l,ll r){
	if(!lzy[rt]) return;
	ll mid=(l+r)>>1;
	lzy[lson]=lzy[rson]=lzy[rt];
	mx[lson]=mx[rson]=lzy[rt];
	sum[lson]=(mid-l+1)*lzy[rt];
	sum[rson]=(r-mid)*lzy[rt];
	lzy[rt]=0;
}
void build(ll rt,ll l,ll r){
	if(l==r){
		mx[rt]=n,sum[rt]=n,lzy[rt]=0;
		return;
	}
	lzy[rt]=0;
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	push_up(rt);
}
ll find(ll rt,ll l,ll r,ll L,ll R,ll V){
	if(l==r){
		if(l>R) return -1;
		return max(l,L);
	}
	push_down(rt,l,r);
	ll mid=(l+r)>>1;
	if(mx[lson]>V){
		return find(lson,l,mid,L,R,V);
	}
	else
	if(mx[rson]>V){
		return find(rson,mid+1,r,L,R,V);
	}
	return -1;
}
void update(ll rt,ll l,ll r,ll L,ll R,ll v){
	if(l>=L&&r<=R){
		sum[rt]=(r-l+1)*v;
		mx[rt]=v;
		lzy[rt]=v;
		return;
	}
	push_down(rt,l,r);
	ll mid=(l+r)>>1;
	if(mid>=L) update(lson,l,mid,L,R,v);
	if(mid<R) update(rson,mid+1,r,L,R,v);
	push_up(rt);
}
void solve(){
	scanf("%lld",&n);
	vector<ll>ans(n+5);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		loc[x]=i;
	}
	build(1,1,n);
	for(int i=n;i>=1;i--){
		vector<ll>v(1);
		for(int j=i;j<=n;j+=i) v.push_back(loc[j]);
		sort(v.begin()+1,v.end());
		ans[i]=sum[1];
		for(int j=1;j+1<v.size();j++){
			int l=find(1,1,n,v[j-1]+1,v[j],v[j+1]-1);
			//cout<<l<<endl;
			if(~l){
				update(1,1,n,l,v[j],v[j+1]-1);
				//cout<<"fff";
			}
		}
		ans[i]-=sum[1];
	}
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
