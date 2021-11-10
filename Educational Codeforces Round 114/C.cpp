#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll sum,a[2000005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	scanf("%d",&m);
	while(m--){
		ll ans=9e18;
		ll x,y;
		scanf("%lld%lld",&x,&y);
		int index=lower_bound(a+1,a+1+n,x)-a;
		if(index<=n){
			ans=min(ans,max(0ll,y-(sum-a[index])));
		}
		if(index>1){
			ans=min(ans,max(0ll,y-(sum-a[index-1]))+(x-a[index-1]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
