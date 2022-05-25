#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150],b[150];
int n;
ll suma=0,sumb=0;
ll ope(){
	for(int i=1;i<=n;i++){
		ll ans1=a[i]*(suma-a[i])+b[i]*(sumb-b[i]),ans2=b[i]*(suma-a[i])+a[i]*(sumb-b[i]);
		if(ans2<ans1){
			suma+=b[i]-a[i];
			sumb+=a[i]-b[i];
			swap(a[i],b[i]);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		ans+=(a[i]+a[j])*(a[i]+a[j])+(b[i]+b[j])*(b[i]+b[j]);
	}
	return ans;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		suma=sumb=0;
		for(int i=1;i<=n;i++){cin>>a[i];suma+=a[i];}
		for(int i=1;i<=n;i++){cin>>b[i];sumb+=b[i];}
		
		/*for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<endl;*/
		ll ans=2147483647000;
		for(int i=1;i<=100;i++){
			ans=min(ans,ope());
		}
		cout<<ans<<endl;
	}
	return 0;
}
