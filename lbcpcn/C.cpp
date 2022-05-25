#include <bits/stdc++.h>
using namespace std;
bool used[250000];
int n,m,ans[2500000];
vector<pair<int,int>>G[250000];
void dfs(int now,int las,int pre){
	if(used[now]) return;
	used[now]=1;
	if(las==pre){
		//cout<<now<<endl;
		if(las+1<=n) ans[now]=las+1;
		else ans[now]=las-1;
	}
	else ans[now]=las;
	//if(now==1) cout<<ans[now]<<endl;
	for(auto to:G[now]){
		int v=to.first,w=to.second;
		dfs(v,w,ans[now]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}
