#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[2000005],y[2000005];
struct Point{
	int x,y;
}p[3005000];
bool cmpX(Point x,Point y){
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
bool cmpY(Point x,Point y){
	if(x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	for(int i=1;i<=k;i++) cin>>p[i].x>>p[i].y;
	if(n==1||m==1){
		cout<<0;
		return;
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+m);
	sort(p+1,p+1+k,cmpX);
	ll ans=0;
	int l=1;
	for(int i=2;i<=n;i++){
		int upper=x[i],lower=x[i-1];
		while(l<=k&&p[l].x<=lower){
			l++;
		}
		if(l>k) break;
		if(p[l].x>=upper) continue;
		int r=l+1;
		while(r<=k&&p[r].x<upper) r++;
		r--;
		//cout<<lower<<" "<<upper<<" "<<l<<" "<<r<<endl;
		//cout<<p[4].x<<endl;
		ll res=0;
		map<int,int>cnt;
		for(int j=l;j<=r;j++){
			res+=cnt[p[j].y];
			cnt[p[j].y]++;
			//cout<<p[j].y<<" "<<res<<endl;
		}
		ll len=(r-l+1);
		ans+=len*(len-1)/2-res;
	}
	sort(p+1,p+1+k,cmpY);
	l=1;
	for(int i=2;i<=m;i++){
		int upper=y[i],lower=y[i-1];
		while(l<=k&&p[l].y<=lower){
			l++;
		}
		if(l>k) break;
		if(p[l].y>=upper) continue;
		int r=l+1;
		while(r<=k&&p[r].y<upper) r++;
		r--;
		//cout<<lower<<" "<<upper<<" "<<l<<" "<<r<<endl;
		//cout<<p[4].x<<endl;
		ll res=0;
		map<int,int>cnt;
		for(int j=l;j<=r;j++){
			res+=cnt[p[j].x];
			cnt[p[j].x]++;
			//cout<<p[j].y<<" "<<res<<endl;
		}
		ll len=(r-l+1);
		ans+=len*(len-1)/2-res;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}