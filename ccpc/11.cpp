#include <bits/stdc++.h>
using namespace std;
struct Node{
	int index,x;	
}a[150000];
int b[150000],sum[150000],ans[150000];
vector<int>G[150000];
int f[150000][35],depth[150000],mx[150000][35];
void dfs(int now,int father){
    depth[now]=depth[father]+1;
    f[now][0]=father;
    mx[now][0]=max(b[now],b[father]);
    for(int i=1;i<=29;i++){
        f[now][i]=f[f[now][i-1]][i-1];
        mx[now][i]=max(mx[now][i-1],mx[f[now][i-1]][i-1]);
    }
    for(int i=0;i<G[now].size();i++){
        int v=G[now][i];
        if(v==father) continue;
        dfs(v,now);
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int res=0;
    for(int i=29;i>=0;i--)
        if(depth[f[u][i]]>=depth[v]) res=max(res,mx[u][i]),u=f[u][i];
    if(u==v) return res;
    for(int i=29;i>=0;i--)
        if(f[u][i]!=f[v][i]) res=max(res,max(mx[u][i],mx[v][i])),u=f[u][i],v=f[v][i];
    return max(res,max(mx[u][0],mx[v][0]));
}
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v),G[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			a[i].index=i;
			scanf("%d",&a[i].x);
			b[i]=a[i].x;
		}
		dfs(1,0);
		/*(int i=1;i<=n;i++){
			cout<<mx[i][2]<<endl;
		}*/
		sort(a+1,a+1+n,cmp);
		queue<int>q;
		for(int i=1;i<=n;i++) q.push(i);
		//while(q.size()>1){
			map<int,bool>c;
			vector<int> tmp;
			queue<int> nxt;
			//cout<<q.size()<<endl;
			while(q.size()) {tmp.push_back(q.front());q.pop();}
			int len=tmp.size();
			//cout<<len<<endl;
			for(int i=0;i<len-1;i++){
				int g=lca(a[tmp[i]].index,a[tmp[i+1]].index);
				//cout<<a[tmp[i]].index<<" "<<a[tmp[i+1]].index<<" "<<g<<endl;
				if(g==a[tmp[i+1]].x) c[i]=1;
				else nxt.push(tmp[i]);
				//cout<<tmp[i]<<" ";
			}
			//cout<<endl;
			sum[len-1]=0;
			for(int i=len-2;i>=0;i--) sum[i]=sum[i+1]+c[i];
			for(int i=0;i<len;i++) ans[a[tmp[i]].index]+=sum[i];
			q=nxt;
		//}
		while(q.size()>1) ans[a[q.front()].index]++,q.pop();
		for(int i=1;i<=n;i++) cout<<ans[i]+1<<endl;
	}
	return 0;
}
/*
		for(int i=1;i<n;i++){
			int g=lca(a[i].index,a[i+1].index);
			if(g==a[i+1].x) c[i]=1;
		}
		sum[n]=0;
		for(int i=n-1;i>=1;i--) sum[i]=sum[i+1]+c[i];
		for(int i=1;i<=n;i++){
			ans[a[i].index]=sum[i]+1;
		}
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<endl;
*/