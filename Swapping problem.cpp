#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=2e5+5;
ll a[MAX],b[MAX],max1[MAX],max2[MAX];

int main(){
	ll n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	vector<pair<ll,ll>>v1,v2;
	for(int i=1;i<=n;i++){
		if(a[i]<b[i]){
			v1.push_back(make_pair(a[i],b[i]));
		}
		else{
			v2.push_back(make_pair(b[i],a[i]));
		}
		ans+=abs(a[i]-b[i]);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<v1.size();i++){
		max1[i+1]=max(max1[i],v1[i].second);
	}
	for(int i=0;i<v2.size();i++){
		max2[i+1]=max(max2[i],v2[i].second);
	}
	ll maxn=0;
	for(auto seg:v1){
		ll fir=seg.first,sec=seg.second;
		auto it=upper_bound(v2.begin(),v2.end(),seg)-v2.begin();
		if(it==0) continue;
		maxn=max(maxn,min(sec,max2[it])-fir);
	}
	for(auto seg:v2){
		ll fir=seg.first,sec=seg.second;
		auto it=upper_bound(v1.begin(),v1.end(),seg)-v1.begin();
		if(it==0) continue;
		maxn=max(maxn,min(sec,max1[it])-fir);
	}
	cout<<ans-2*maxn;
	return 0;
}
