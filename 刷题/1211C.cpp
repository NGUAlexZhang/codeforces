#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Ice{
	ll a,b,c;
}ice[205000];
bool cmp(Ice a,Ice b){
	return a.c<b.c;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>ice[i].a>>ice[i].b>>ice[i].c;
	sort(ice+1,ice+1+n,cmp);
	ll upper=0,lower=0;
	for(int i=1;i<=n;i++) upper+=ice[i].b,lower+=ice[i].a;
	if(k>upper||k<lower){
		cout<<"-1";
		return 0;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=(ice[i].a*ice[i].c);
	}
	for(int i=1;i<=n;i++){
		if(lower+ice[i].b-ice[i].a<=k){
			ans+=(ice[i].b-ice[i].a)*ice[i].c;
			lower+=ice[i].b-ice[i].a;
			continue;
		}
		int x=k-lower;
		lower+=x;
		ans+=x*ice[i].c;
	}
	cout<<ans;
	return 0;
}