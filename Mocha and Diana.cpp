#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int fa1[N],fa2[N];
vector<pair<int,int> >ans;
int find(int* fa,int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa,fa[x]);
}
int main(){
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++) fa1[i]=i,fa2[i]=i;
	for(int i=1;i<=m1;i++){
		int u,v;
		cin>>u>>v;
		fa1[find(fa1,u)]=find(fa1,v);
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		cin>>u>>v;
		fa2[find(fa2,u)]=find(fa2,v);
	}
	int rt=1;
	//cout<<find(fa2,rt)<<" "<<find(fa2,5);
	for(int i=1;i<=n;i++){
		if(find(fa1,i)!=find(fa1,rt)&&find(fa2,i)!=find(fa2,rt)){
			ans.push_back({rt,i});
			fa1[find(fa1,i)]=find(fa1,rt);
			fa2[find(fa2,i)]=find(fa2,rt);
		}
	}
	stack<int>s1;
	stack<int>s2;
	for(int i=1;i<=n;i++){
		if(find(fa1,i)!=find(fa1,rt)&&find(fa2,i)==find(fa2,rt)) s1.push(i);
		if(find(fa1,i)==find(fa1,rt)&&find(fa2,i)!=find(fa2,rt)) s2.push(i);
	}
	while(s1.size()&&s2.size()){
		int u=s1.top(),v=s2.top();
		ans.push_back({u,v});
		fa1[find(fa1,u)]=find(fa1,rt);
		fa2[find(fa2,v)]=find(fa2,rt);
		while(s1.size()&&find(fa1,s1.top())==find(fa1,rt)) s1.pop();
		while(s2.size()&&find(fa2,s2.top())==find(fa2,rt)) s2.pop();
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}
