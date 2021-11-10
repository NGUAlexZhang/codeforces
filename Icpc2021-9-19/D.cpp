#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
bool flag[N<<2],m[N<<2];
long long ans=0,cnt;
struct Seg{
	ll l,r,w;
}seg[N];
bool cmp(Seg a,Seg b){
	return a.w<b.w;
}
void update(int L,int R,int l,int r,int rt,int w){
	if(l>=L&&r<=R){
		ll len=(r-l+1);
		if(flag[rt]){
			return; 
		}
		if(!m[rt]){
			m[rt]=1;
			ans+=len*w;
			flag[rt]=1;
			return;
		}
	}
	int mid=(l+r)>>1;
	if(mid>=L){
		update(L,R,l,mid,rt<<1,w);
	}
	if(R>mid){
		update(L,R,mid+1,r,rt<<1|1,w);
	}
	flag[rt]=flag[rt<<1]&&flag[rt<<1|1];
	m[rt]=1;
}
void solve(){
	ans=0;
	memset(m,0,sizeof(m));
	memset(flag,0,sizeof(flag));
	int n,m;
	cin>>n>>m;ll sum=0;
	for(int i=1;i<=m;i++){
		//cin>>seg[i].l>>seg[i].r>>seg[i].w;
		cin>>seg[i].l>>seg[i].r>>seg[i].w;
		sum+=(seg[i].r-seg[i].l+1)*(seg[i].r-seg[i].l)/2*seg[i].w;
		seg[i].r--;
	}
	sort(seg+1,seg+1+m,cmp);
	//cout<<sum<<endl;
	for(int i=1;i<=m;i++){
		update(seg[i].l,seg[i].r,1,n-1,1,seg[i].w);
		//cout<<ans<<endl;
	}
	//cout<<flag[2]<<" "<<flag[3]<<endl;
	printf("Case #%lld: ",++cnt);
	if(flag[1])
		printf("%lld\n",sum-ans);
	else printf("Gotta prepare a lesson\n");
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}