#include <bits/stdc++.h>
using namespace std;
int p[200005],val[200005],ans[200005],b[200005];
vector<int>G[200005];

int main(){
	int T;
	cin>>T;
	while(T--){
		map<int,bool>m;
		int n;
		cin>>n;
		int root=0;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			b[i]=x;
			if(x==i){
				root=i;
				continue;
			}
			G[x].push_back(i);
		}
		for(int i=1;i<=n;i++) cin>>p[i];
		m[root]=1;
		int tot=0;
		bool flag=0;
		for(int i=1;i<=n;i++){
			int u=p[i];
			if(!m[u]){
				flag=1;
				cout<<-1<<endl;
				break;
			}
			val[u]=tot;
			tot++;
			for(auto v:G[u]){
				m[v]=1;
			}
		}
		if(flag){
			continue;
		}
		//dfs(root);
		for(int i=1;i<=n;i++){
			if(i==b[i]){
				cout<<0<<" ";
				continue;
			}
			cout<<val[i]-val[b[i]]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
