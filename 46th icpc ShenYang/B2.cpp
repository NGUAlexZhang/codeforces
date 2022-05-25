#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int>>G[150000];
int n,m,col[150000],flag;
ll cnt0[40],cnt1[40];
ll ans;
void dfs(int now,int color){
	if(flag) return;
	col[now]=color;
	for(int i=0;i<=30;i++){
		if((color>>i)&1) cnt1[i]++;
		else cnt0[i]++;
	}
	for(auto node:G[now]){
		int v=node.first,w=node.second;
		if(col[v]==-1) dfs(v,color^w);
		else
		if(col[v]!=(color^w)){
			flag=1;
			return;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) col[i]=-1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=n;i++){
		if(col[i]!=-1) continue;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt0,0,sizeof(cnt0));
		dfs(i,0);
		if(flag){
			cout<<-1;
			return 0;
		}
		for(int i=0;i<=30;i++){
			ans+=min(cnt0[i],cnt1[i])*(1ll*(1<<i));
		}
	}
	cout<<ans;
	return 0;
}
