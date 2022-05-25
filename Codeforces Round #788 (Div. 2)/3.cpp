#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
ll a[150000];
int main(){
	cin>>n>>k;
	ll ans=2147483647;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i+k-1<=n;i++){
		if(a[i]*a[i+k-1]<0){
			ans=min(ans,min(abs(a[i]),abs(a[i+k-1]))*2+max(abs(a[i]),abs(a[i+k-1])));
		}
		else{
			ans=min(ans,max(abs(a[i]),abs(a[i+k-1])));
		}
	}
	cout<<ans;
	return 0;
}
