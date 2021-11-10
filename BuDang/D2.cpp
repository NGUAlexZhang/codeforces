#include <bits/stdc++.h>
using namespace std;
int fa[500005];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main(){
    int n,m1,m2;
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=2*n;i++){
    	fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		fa[i+n]=i;
	}
	for(int i=1;i<=m1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v))
			fa[find(u)]=find(v);
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v))
			fa[find(u)]=find(v);
	}
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(fa[i]==i) ans.push_back(i);
	}
	printf("%lld",ans.size()-1);
	for(int i=1;i<ans.size();i++){
		printf("%d %d\n",ans[i-1],ans[i]);
	}
    return 0;
}