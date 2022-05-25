#include <bits/stdc++.h>
using namespace std;
struct Monster{
	int k,h,l,r;
}m[1000];
bool cmp(Monster a,Monster b){
	return a.l<b.l;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>m[i].k;
		for(int i=1;i<=n;i++) cin>>m[i].h;
		for(int i=1;i<=n;i++){
			m[i].r=m[i].k;
			m[i].l=m[i].r-m[i].h+1;
		}
		sort(m+1,m+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			int r=m[i].r;
			int maxn=0;
			int j;
			for(j=i+1;j<=n&&m[j].l<=r;j++){
				r=max(r,m[j].r);
			}
			j--;
			long long num=r-m[i].l+1;
			ans+=num*(num+1)/2;
			i=j;
		}
		cout<<ans<<endl;
	}
	return 0;
}
