#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150],mex[150][150];
ll getMex(int l,int r){
	map<ll,bool>m;
	for(int i=l;i<=r;i++) m[a[i]]=1;
	int ans=0;
	while(m[ans]) ans++;
	return ans;
}
ll getAns(int l,int r){
	ll dp[150];
	memset(dp,0,sizeof(dp));
	dp[l-1]=0;
	for(int i=l;i<=r;i++){
		for(int j=l-1;j<i;j++) dp[i]=max(dp[i],dp[j]+mex[j+1][i]+1);
	}
	return dp[r];
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) mex[i][j]=getMex(i,j);
		ll ans=0;
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) ans+=getAns(i,j);
		cout<<ans<<endl;
	}
	return 0;
}
