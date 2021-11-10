#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200000];
long long sum[200000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll ans=sum[n]-sum[1]-(n-1)*a[1],index=1;
	for(int i=1;i<=n;i++){
		/*if((i-1)*a[i]-sum[i-1]+sum[n]-sum[i]-(n-i)*a[i]>ans){
			ans=(i-1)*a[i]-sum[i-1]+sum[n]-sum[i]-(n-i)*a[i];
			index=i;
		}*/
		ans=min(ans,(i-1)*a[i]-sum[i-1]+sum[n]-sum[i]-(n-i)*a[i]);
	}
	cout<<ans;
	return 0;
}
