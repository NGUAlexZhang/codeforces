#include <bits/stdc++.h>
using namespace std;
int msb[200005];
vector<int>G[200005];
vector<int>color[2];
void init(){
	for(int i=1;i<=200000;i++){
		int cnt=0;
		for(int j=i;j;j/=2) cnt++;
		msb[i]=cnt-1;
	}
}
void paint(int now,int pa,int col){
	color[col].push_back(now);
	for(int v:G[now]){
		if(v==pa) continue;
		paint(v,now,col^1);
	}
}
int main(){
	init();
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>ans(n+5);
		vector<int>nodes[30];
		color[0].clear(),color[1].clear();
		for(int i=1;i<=n;i++){
			G[i].clear();
			nodes[msb[i]].push_back(i);
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		paint(1,0,0);
		for(int i=21;i>=0;i--){
			int col=0;
			if(color[col^1].size()>color[col].size()) col^=1;
			for(int j:nodes[i]){
				ans[color[col].back()]=j;
				color[col].pop_back();
			}
		}
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
