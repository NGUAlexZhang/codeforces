#include <bits/stdc++.h>
using namespace std;
vector<int>G[2000005];
int type[2000005];
void dfs(int now,int pre){
	bool leave=1;
	for(auto v:G[now]){
		if(v==pre) continue;
		dfs(v,now);
		if(type[v]==1) leave=0;
	}
	if(leave) type[now]=1;
	else type[now]=2;
}
int main(){
	int T;
	cin>>T;
	while(T --> 0){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			G[i].clear();
			type[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		dfs(1,0);
		bool leaf=0;
		for(auto v:G[1]){
			if(type[v]==1) leaf=1;
		}
		int k=0;
		for(int i=2;i<=n;i++){
			k+=(type[i]==2);
		}
		cout<<n-2*k-leaf<<endl;
	}
	return 0;
}