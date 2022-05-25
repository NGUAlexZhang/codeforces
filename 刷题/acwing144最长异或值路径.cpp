#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
int n,b[150000],a[40],trie[5000000][2],tot=1;
vector<pair<int,int>>G[150000];
void dfs(int now,int fa,int num){
	b[now]=num;
	for(auto seg:G[now]){
		int v=seg.first,w=seg.second;
		if(v==fa) continue;
		dfs(v,now,num^w);
	}
}
void get(){
	int p=1;ll res=0;
	for(int i=31;i>=1;i--){
		int ch=a[i];
		if(trie[p][ch^1]){
			res+=(1<<(i-1));
			p=trie[p][ch^1];
		}
		else p=trie[p][ch];
	}
	ans=max(ans,res);
}
void insert(){
	int p=1;
	for(int i=31;i>=1;i--){
		int ch=a[i];
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u++,v++;
		G[u].push_back(make_pair(v,w)),G[v].push_back(make_pair(u,w));
	}
	dfs(1,0,0);
	bool flag=0;
	for(int i=1;i<=n;i++){
		int x=b[i];
		for(int j=30;j>=0;j--){
			a[j+1]=(x>>j)&1;
		}
		if(flag) get();
		insert();
		flag=1;
	}
	cout<<ans;
	return 0;
}
