#include <bits/stdc++.h>
using namespace std;
vector<int>G[150000];
pair<int,int> node[150000];
bool vis[150000];
int ans[150000],fa[150000],nxt[150000];
int find(int x){
	return (x==fa[x])?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);nxt[x]=y;
	fa[x]=y;
}
int dfs(int now){
//	cout<<now<<endl;
	if(ans[now]) return ans[now];
	if(nxt[now]==0) return ans[now]=1;
	return ans[now]=dfs(nxt[now])+1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			G[i].clear();
			ans[i]=0;
			vis[i]=0,fa[i]=i,nxt[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&node[i].first);node[i].second=i;
		}
		sort(node+1,node+1+n);
		for(int i=1;i<=n;i++){
			int u=node[i].second;
			vis[u]=1;
			for(auto v:G[u]){
				if(!vis[v]) continue;
				vis[v]=1;
				merge(v,u);
			}
		}
//		for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
		//cout<<endl;
		for(int i=1;i<=n;i++) dfs(i);
		for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
