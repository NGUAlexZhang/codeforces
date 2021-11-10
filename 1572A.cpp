#include <bits/stdc++.h>
using namespace std;
vector<int>G[250005];
int in[250005],d[250006],n;
bool used[250005];
void solve(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i),used[i]=1,d[i]=1;
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			in[v]--;
			d[v]=max(d[v],d[u]+(v<u));
			if(!in[v]){
				q.push(v);
				used[v]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!used[i]){
			printf("-1\n");
			return;
		}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d[i]);
	printf("%d\n",ans);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) in[i]=0,used[i]=0,d[i]=0,G[i].clear();
		for(int i=1;i<=n;i++){
			int ki=0;
			scanf("%d",&ki);
			for(int j=1;j<=ki;j++){
				int v;
				scanf("%d",&v);
				G[v].push_back(i);
				in[i]++;
			}
		}
		solve();
	}
	return 0;
}
