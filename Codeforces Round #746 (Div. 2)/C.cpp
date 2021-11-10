#include <bits/stdc++.h>
using namespace std;
vector<int>G[150000];
int a[150000],ans,b[150000],cnt;
void dfs(int now,int fa){
	for(int i=0;i<G[now].size();i++){
		int v=G[now][i];
		if(v==fa) continue;
		dfs(v,now);
		if(b[v]!=ans) b[now]^=b[v];
	}
	if(b[now]==ans) {
		cnt++;
		//cout<<now<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		ans=0,cnt=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),G[i].clear(),ans^=a[i],b[i]=a[i];
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		//cout<<ans<<endl;
		if(!ans){
			puts("YES");continue;
		}
		dfs(1,0);
		if(k>2&&cnt>=3) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
111
100
001
010
*/