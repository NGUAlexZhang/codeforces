#include <bits/stdc++.h>
using namespace std;
int n,m,t,match[10005],ans;
bool vis[10005];
map<pair<int,int>,bool>c;
bool dfs(int now){
	for(int i=1;i<=m;i++){
		if(c[{now,i}]) continue;
		if(vis[i]) continue;
		vis[i]=1;
		if(!match[i]||dfs(match[i])){
			match[i]=now;return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		c[{x,y}]=1;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
}
