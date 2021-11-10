#include <bits/stdc++.h>
using namespace std;
int n,m,fa[150050];
int Empty[150050];
struct Edge{
	int u,v,w;
	bool operator <(const Edge& a){
		return w>a.w;
	}
}e[150050];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;	
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)){
			cout<<e[i].w;
			return 0;
		}
		if(Empty[u]) fa[find(Empty[u])]=find(v);
		else Empty[u]=v;
		if(Empty[v]) fa[find(Empty[v])]=find(u);
		else Empty[v]=u;
	}
	cout<<0;
	return 0;
}