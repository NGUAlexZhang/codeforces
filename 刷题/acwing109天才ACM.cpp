#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll t;
ll a[550000],b[550000];
bool check(int l,int r){
	int k=0;
	for(int i=l;i<r;i++) b[++k]=a[i];
	sort(b+1,b+1+k);
	int lp=1,rp=k;
	int cnt=m;
	ll sum=0;
	while(lp<rp&&cnt){
		sum+=(b[lp]-b[rp])*(b[lp]-b[rp]);
		lp++,rp--;
		cnt--;
		if(sum>t) return 0;
	}
	return 1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>t;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int now=1,ans=0;
		while(now<=n){
			int r=now,p=1,flag=1;
			while(p&&r<=n+1){
				flag=0;
				if(r+p<=n+1&&check(now,r+p)){
					r+=p;
					p<<=1;
				}
				else p>>=1;
			}
			ans++;
			now=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}
