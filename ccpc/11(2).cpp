#include <bits/stdc++.h>
using namespace std;
int ans[150000],b[150000];
int G[150000];
struct Node{
	int index,x;	
}a[150000];
void dfs(int now,int node){
	
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			a[i].index=i;
			scanf("%d",&a[i].x);
			b[i]=a[i].x;
		}
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
