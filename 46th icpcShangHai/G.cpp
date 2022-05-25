#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
vector<int>G[100005];
ll ans1[100005],ans2[100005],l[100005];
void dfs(int now,int fa){
	ll res=1,cnt=0;
	for(int v:G[now]){
		if(v==fa) continue;
		dfs(v,now);
		res*=ans1[v];
		res%=MOD;
		if(ans2[v]==0) cnt++;
	}
	ans1[now]=res;
	ans1[now]=(ans1[now]*l[cnt/2])%MOD;
	if(cnt%2) ans1[now]=(ans1[now]*cnt)%MOD;
	ans2[now]=cnt%2;
}
int main(){
	l[0]=1;
	for(int i=1;i<=100000;i++){
		l[i]=l[i-1]*(2*i-1);
		l[i]%=MOD;
	}
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans1[1];
	return 0;
}
