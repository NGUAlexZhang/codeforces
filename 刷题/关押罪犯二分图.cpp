#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >G[25000];
int n,m;
int color[25000];
bool yes=1;
void dfs(int now,int c,int x){
	color[now]=c;
	for(int i=0;i<G[now].size();i++){
		if(G[now][i].first<=x) continue;
		int v=G[now][i].second;
		if(color[v]){
			if(color[v]==c) {yes=0;return;}
		}
		else
			dfs(v,3-c,x);
	}
}
bool check(int x){
	yes=1;
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++){
		if(yes==0) return 0;
		if(color[i]==0)
			dfs(i,1,x);
	}
	return yes;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
	int l=0,r=1e9+5;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<r+1<<endl;
	return 0;
}
