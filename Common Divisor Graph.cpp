#include <bits/stdc++.h>
using namespace std;
int n,q,fa[1000500];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(find(x)==find(y)) return;
	fa[find(x)]=find(y);
}
int main(){
	cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) {cin>>a[i];}
	int maxn=*max_element(a.begin(),a.end());
	for(int i=1;i<=maxn;i++) fa[i]=i;
	vector<vector<int> >divisor(maxn+2);
	for(int i=2;i<=maxn+1;i++){
		if(divisor[i].size()) continue;
		for(int j=i;j<=maxn+1;j+=i) divisor[j].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=0;j<divisor[x].size();j++){
			merge(x,divisor[x][j]);
		}
	}
	map<pair<int,int>,bool>m;
	for(int i=1;i<=n;i++){
		vector<int> node=divisor[a[i]+1];
		node.push_back(a[i]);
		for(int j=0;j<node.size();j++){
			for(int k=j+1;k<node.size();k++){
				int fir=find(node[j]),sec=find(node[k]);
				m[{fir,sec}]=1,m[{sec,fir}]=1;
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		u=a[u],v=a[v];
		if(find(u)==find(v)){
			puts("0");
		}
		else
		if(m[{find(u),find(v)}])
		puts("1");
		else puts("2");
	}
	return 0;
}
