#include <bits/stdc++.h>
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n,t;
int match[15000],ans;
bool vis[15000];
vector<int>G[15000];
map<int,bool>banned;
bool dfs(int now){
	for(int i=0;i<G[now].size();i++){
		int v=G[now][i];
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||dfs(match[v])){
			match[v]=now;return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		banned[(x-1)*n+y]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(banned[(i-1)*n+j]) continue;
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x<1||x>n||y<1||y>n||banned[(x-1)*n+y]) continue;
				//cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
				G[(i-1)*n+j].push_back((x-1)*n+y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)%2) continue;
			memset(vis,0,sizeof(vis));
			if(dfs((i-1)*n+j)) ans++;
		}
	}
	cout<<ans;
	return 0;
}
