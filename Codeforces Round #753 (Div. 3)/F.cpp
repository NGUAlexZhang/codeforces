#include <bits/stdc++.h>
using namespace std;
char s[2005][2005];
vector<int> nxt,d,in;
vector<bool> used;
int n,m;
void cal(int st,int now,int step){
	if(nxt[now]==st){
		d[now]=step+1;
		return;
	}
	cal(st,nxt[now],step+1);
	d[now]=d[nxt[now]];
}
void topo(){
	queue<int>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(in[(i-1)*m+j]==0) q.push((i-1)*m+j);
	while(q.size()){
		int now=q.front();q.pop();
		if(nxt[now]){
			in[nxt[now]]--;
			if(in[nxt[now]]==0){
				q.push(nxt[now]);
			}
		}
	}
}
void dfs(int x,int y){
	int nx=x,ny=y;
	if(s[x][y]=='L') ny--;
	if(s[x][y]=='R') ny++;
	if(s[x][y]=='U') nx--;
	if(s[x][y]=='D') nx++;
	if(nx<1||nx>n||ny<1||ny>m) return;
	nxt[(x-1)*m+y]=(nx-1)*m+ny;
	in[(nx-1)*m+ny]++;
}
int get(int now){
	if(d[now]) return d[now];
	d[now]=1;
	//cout<<now<<endl;
	if(nxt[now]){
		//used[nxt[now]]=1;
		d[now]=get(nxt[now])+1;
		//used[nxt[now]]=0;
	}
	return d[now];
}
int main(){
	int T;
	cin>>T;
	while(T--){
		in.clear(),nxt.clear(),d.clear();
		scanf("%d%d",&n,&m);
		in.resize(n*m+5),nxt.resize(n*m+5),d.resize(n*m+5);
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			dfs(i,j);
		}
		topo();
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(d[(i-1)*m+j]==0&&in[(i-1)*m+j]) cal((i-1)*m+j,(i-1)*m+j,0);
		}
		int ans=0,ansx=0,ansy=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			//cout<<d[2]<<endl;
			get((i-1)*m+j);
			//cout<<d[2]<<endl;
			if(d[(i-1)*m+j]>ans){
				ans=d[(i-1)*m+j];
				ansx=i,ansy=j;
			}	
		}
		printf("%d %d %d\n",ansx,ansy,ans);
	}
	return 0;
}
