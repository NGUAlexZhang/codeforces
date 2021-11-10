#include <bits/stdc++.h>
using namespace std;
vector<int>G[1500000];
int n,d,a[1500000],dis[1500000],used[1500000];
int step(int now){
	now+=d;
	if(now>n) now-=n;
	return now;
}
void bfs(){
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!a[i]) q.push(i),dis[i]=0,used[i]=1;
	while(q.size()){
		int u=q.front();q.pop();used[u]=0;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				if(!used[v]){
					used[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&d);
		map<int,bool>m;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),G[i].clear();
		for(int i=1;i<=n;i++){
			int now=i;
			while(!m[now]){
				m[now]=1;
				int nxt=step(now);
				//cout<<now<<" "<<nxt<<endl;
				G[now].push_back(nxt);
				now=nxt;
			}
		}
		bfs();
		bool flag=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(dis[i]==dis[0]) flag=1;
			ans=max(ans,dis[i]);
			//cout<<dis[i]<<" ";
		}
		if(flag) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
