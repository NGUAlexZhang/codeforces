#include <bits/stdc++.h>
using namespace std;
char s[505][500];
int mapp[505][505],color[255000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int>G[255000];
void dfs(int now,int c){
	color[now]=c;
	for(int i=0;i<G[now].size();i++){
		int v=G[now][i];
		if(color[v]) continue;
		dfs(v,3-c);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(s[i]+1);
	}
	//cout<<mapp[4][6];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(s[i][j]=='.') continue;
		vector<int>v;
		for(int k=0;k<4;k++){
			int tx=i+dx[k],ty=j+dy[k];
			if(tx<1||tx>n||ty<1||ty>m) continue;
			if(s[tx][ty]=='.') mapp[i][j]++,v.push_back((tx-1)*n+ty);
		}
		if(mapp[i][j]%2){
			//cout<<i<<" "<<j;
			puts("NO");return 0;
		}
		mapp[i][j]=v.size()/2*5;
		int siz=v.size();
		for(int k=0;k<siz;k+2) {
			//cout<<v[k]<<" "<<v[k+1]<<endl;
			G[v[k]].push_back(v[k+1]);G[v[k+1]].push_back(v[k]);	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(!color[(i-1)*n+j]&&mapp[i][j]==0){
				//cout<<i<<" "<<j<<endl;
				dfs((i-1)*n+j,1);
			}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]!='.') cout<<mapp[i][j];
			else if(color[(i-1)*n+j]==1) cout<<1;
			else cout<<4;
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
