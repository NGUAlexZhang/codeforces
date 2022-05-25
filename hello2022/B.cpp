#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,ll> seg[250000];
ll c[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int minn=0,maxx=0,tmp=0;ll maxnum=-1,minnum=2147483647;
		seg[0].second=-2147483647,seg[0].first=2147483647;
		for(int i=1;i<=n;i++){
			cin>>seg[i].first>>seg[i].second>>c[i];
		}
		for(int i=1;i<=n;i++){
			minnum=min(minnum,seg[i].first);
			maxnum=max(maxnum,seg[i].second);
			
			if(seg[i].first<seg[minn].first){
				minn=i;
			}
			if(seg[i].second>seg[maxx].second){
				maxx=i;
			}
			if(seg[i].first==seg[minn].first){
				if(c[i]<c[minn]) minn=i;
			}
			if(seg[i].second==seg[maxx].second){
				if(c[i]<c[maxx]) maxx=i;
			}
			if(seg[tmp].first==minnum&&seg[tmp].second==maxnum){
				if(seg[i].first==minnum&&seg[i].second==maxnum&&c[i]<c[tmp]) tmp=i;
			}
			else if(seg[i].first==minnum&&seg[i].second==maxnum) tmp=i;
			ll now=c[minn]+c[maxx];
			if(seg[tmp].first==minnum&&seg[tmp].second==maxnum){
				now=min(now,c[tmp]);
			}
			cout<<now<<endl;
		}
	}
	return 0;
}
