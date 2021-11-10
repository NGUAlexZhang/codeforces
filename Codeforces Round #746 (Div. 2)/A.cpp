#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;ll h;
		cin>>n>>h;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		int cnt=0;
		ll sum=a[n]+a[n-1];
		ll ans=0;
		ans+=(h/sum)*2;
		h%=sum;
		if(h>0){
		
		if(h<=a[n]){
			ans++;
		}
		else ans+=2;
	}
		cout<<ans<<endl;
	}
	return 0;
}
