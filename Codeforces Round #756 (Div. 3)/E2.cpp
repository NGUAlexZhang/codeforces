#include <bits/stdc++.h>
#define ll long long
using namespace std;
int x[250000];
int n,k,ans;
vector<int>G[250000];
bool flag;
void bfs(){
	map<int,int>used;
	map<int,int>f;
	queue<int>q;
	for(int i=1;i<=k;i++) q.push(x[i]),used[x[i]]=1;
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:G[u]){
			if(used[v]) continue;
			used[v]=used[u]+1;
			q.push(v);
		}
	}
	q.push(1);f[1]=1;
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:G[u]){
			if(f[v]) continue;
			if(f[u]+1>=used[v]){
				ans++;
				continue;
			}
			f[v]=f[u]+1;
			if(G[v].size()==1&&v!=1) flag=1;
			q.push(v);
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=k;i++)
			cin>>x[i];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);G[v].push_back(u);
		}
		flag=0,ans=0;
		bfs();
		if(flag){
			cout<<"-1"<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}
