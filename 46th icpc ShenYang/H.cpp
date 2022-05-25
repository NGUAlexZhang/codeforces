#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,dfn[150000],low[150000],tim,siz[150000];
ll sum;
vector<pair<int,int>>G[150000];
void tarjan(int now,int fa){
	dfn[now]=low[now]=++tim;
	for(auto node:G[now]){
		int v=node.first,w=node.second;
		if(v==fa) continue;
		if(!dfn[v]){
			siz[now]++;
			tarjan(v,now);
			siz[now]+=siz[v];
			low[now]=min(low[now],low[v]);
		}
		else{
			low[now]=min(low[now],dfn[v]);
			if(dfn[v]>dfn[now]) siz[now]++;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w)),G[v].push_back(make_pair(u,w));
		sum+=w;
	}
	if(m%2==0){
		cout<<sum;return 0;
	}
	tarjan(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(auto node:G[i]){
			int v=node.first,w=node.second;
			if(dfn[v]<dfn[i]) continue;
			if(low[v]<=dfn[i]||siz[v]%2==0) ans=max(ans,sum-w);
		}
	}
	cout<<ans;
	return 0;
}
