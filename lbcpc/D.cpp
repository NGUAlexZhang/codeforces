#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Cave{
	int k;
	ll x;
}a[1000005];
bool cmp(Cave a,Cave b){
	return a.x<b.x;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			a[i].k=k;
			ll cnt=0,ans=0;
			for(int j=1;j<=k;j++){
				ll x;
				cin>>x;
				if(cnt<=x){
					ans+=(x+1-cnt);
					cnt=x+1;
				}
				cnt++;
			}
			a[i].x=ans;
		}
		sort(a+1,a+1+n,cmp);
		ll cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt<a[i].x){
				ans+=(a[i].x-cnt);
				cnt=a[i].x;
			}
			cnt+=a[i].k;
		}
		cout<<ans<<endl;
	}
	return 0;
}
