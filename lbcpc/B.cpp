#include <bits/stdc++.h>
using namespace std;
int a[250000],b[250000],loc[250000],maxn[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=2*n+100;
		for(int i=1;i<=n;i++) {cin>>a[i];loc[a[i]]=i;}
		int now=0;
		for(int i=1;i<=n;i++) {
			cin>>b[i];
			if(b[i]==2*n) now=i;
			maxn[i]=maxn[i-1];
			if(b[maxn[i]]<b[i]){
				maxn[i]=i;
			}
		}
		for(int i=2*n-1;i>=1;i-=2){
			while(b[maxn[now-1]]>i) now=maxn[now-1];
			ans=min(ans,loc[i]+now-2);
		}
		cout<<ans<<endl;
	}
	return 0;
}