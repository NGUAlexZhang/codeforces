#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int>G[4005];
int siz[4005];
ll f[4005][2005][2],g[2005][2];
ll p[2005];
const int mod=998244353;
void dfs(int now,int fa){
	f[now][0][0]=1;
	siz[now]=1;
	for(auto v:G[now]){
		if(v==fa) continue;
		dfs(v,now);
		for(int i=0;i<=n+5;i++) g[i][0]=g[i][1]=0; 
		for(int i=0;i<=siz[now]/2;i++)
		for(int j=0;j<=siz[v]/2;j++){
			if(j){
				g[i+j][0]+=(f[v][j][0]+f[v][j][1])%mod*f[now][i][0]%mod;
				g[i+j][1]+=(f[v][j][0]+f[v][j][1])%mod*f[now][i][1]%mod;
			}
			
			g[i+j+1][1]+=f[now][i][0]*f[v][j][0]%mod;
		}
		siz[now]+=siz[v];
		for(int i=0;i<=siz[now]/2+1;i++) f[now][i][0]+=g[i][0],f[now][i][1]+=g[i][1],
		f[now][i][0]%=mod,f[now][i][1]%=mod;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<2*n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=(p[i-1]*(2*i-1))%mod;
	ll ans=p[n];
	//cout<<ans<<endl;
	int tmp=-1;
	for(int i=1;i<=n;i++){
		ans+=tmp*(f[1][i][0]+f[1][i][1])*p[n-i];
		//cout<<f[1][i][0]<<" "<<f[1][i][1]<<endl;
		ans+=mod,ans%=mod;
		tmp*=-1;
	}
	cout<<ans;
	return 0;
}
