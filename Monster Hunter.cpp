#include <bits/stdc++.h>
#define inf 100000000000000
#define ll long long
using namespace std;
ll hp[5000],dp[4000][4000][2],siz[4000],g[4000][2];
vector<int>G[5000];
void dfs(int now,int fa){
	siz[now]=1;
	dp[now][0][0]=hp[now];
	for(auto v:G[now]){
		if(v==fa) continue;
		dfs(v,now);
		for(int i=0;i<=siz[now]+siz[v];i++) g[i][0]=g[i][1]=inf;
		for(int i=0;i<=siz[now];i++){
			for(int j=0;j<=siz[v];j++){
				if(i+j<siz[now]+siz[v]){
					g[i+j][0]=min(g[i+j][0],dp[now][i][0]+dp[v][j][0]+hp[v]);
					if(j>0) g[i+j][0]=min(g[i+j][0],dp[now][i][0]+dp[v][j][1]);
				}
				if(i>0){
					g[i+j][1]=min(g[i+j][1],dp[now][i][1]+dp[v][j][0]);
					if(j>0) g[i+j][1]=min(g[i+j][1],dp[now][i][1]+dp[v][j][1]);
				}
			}
		}
		siz[now]+=siz[v];
		for(int i=0;i<=siz[now];i++) dp[now][i][0]=g[i][0],dp[now][i][1]=g[i][1];
	}
	//for(int i=0;i<=siz[now];i++) dp[now][i][0]+=hp[now];
}
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=0;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		G[x].push_back(i),G[i].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>hp[i];
	dfs(1,0);
	for(int i=0;i<=n;i++) cout<<min(dp[1][i][0],dp[1][i][1])<<" ";
	cout<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}