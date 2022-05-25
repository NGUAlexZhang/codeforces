#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5500];
int main(){
	int n;
	cin>>n;
	ll ans=1e18;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ll sum=0,las=0;
		for(int j=i+1;j<=n;j++){
			ll tmp=(las/a[j]);
			sum+=tmp+1;
			las=(tmp+1)*a[j];
		}
		las=0;
		for(int j=i-1;j>=1;j--){
			ll tmp=(las/a[j]);
			sum+=tmp+1;
			las=(tmp+1)*a[j];
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
