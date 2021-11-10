#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005],sum[1000005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		ll ans=a[1];
		for(int i=2;i<=n;i++) ans=max(ans,a[i]-a[i-1]);
		cout<<ans<<endl;
	}
	return 0;
}
