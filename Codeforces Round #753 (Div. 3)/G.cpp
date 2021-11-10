#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[200005],minn[200005],maxx[200005],ans[200005];
ll n,m;
void print(bool flag){
	if(flag) 
		for(int i=1;i<=n;i++){
			cout<<min(a[i],m)<<" "<<max(m-a[i],0ll)<<endl;
		}
	else
		for(int i=1;i<=n;i++)
			cout<<max(m-b[i],0ll)<<" "<<min(b[i],m)<<endl;	
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
		for(int i=1;i<=n;i++){
			maxx[i]=(b[i]-max(0ll,m-a[i]))-max(0ll,a[i]-m);
			minn[i]=max(0ll,b[i]-m)-(a[i]-max(0ll,m-b[i]));
		}
		ll summin=0,summax=0;
		for(int i=1;i<=n;i++) summin+=minn[i],summax+=maxx[i];
		//cout<<summin<<" "<<summax<<endl;
		if(summin*summax==0){
			cout<<0<<endl;
			if(summin==0) print(0);
			else print(1);
			continue;
		}
		if(summin*summax>0){
			if(summax>0){
				cout<<summin<<endl;
				print(0);
			}
			else{
				cout<<-summax<<endl;
				print(1);
			}
			continue;
		}
		//cout<<summax<<" "<<summin<<endl;
		ll tar=abs(summax)%2;
		cout<<tar<<endl;
		for(int i=1;i<=n;i++){
			if(summin+(maxx[i]-minn[i])<=tar){
				ans[i]=maxx[i];
				summin+=maxx[i]-minn[i];
				continue;
			}
			ll tmp=tar+minn[i]-summin;
			//if(tmp%2!=abs(minn[i])%2) continue;
			ans[i]=tmp;
			summin=tar;
			//break;
		}
		for(int i=1;i<=n;i++){
			//cout<<ans[i]<<endl;
			if(minn[i]==ans[i]){
				cout<<max(m-b[i],0ll)<<" "<<min(b[i],m)<<endl;
				continue;
			}
			if(maxx[i]==ans[i]){
				cout<<min(a[i],m)<<" "<<max(m-a[i],0ll)<<endl;
				continue;
			}
			ll ans1=max(m-b[i],0ll),ans2=min(b[i],m);
			ll tmp=(ans[i]-minn[i])/2;
			//cout<<tmp<<endl;
			cout<<ans1+tmp<<" "<<ans2-tmp<<endl;
		}
	}
	return 0;
}
