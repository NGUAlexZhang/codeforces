#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
double a[1005][1005],ans[1005][1005];
bool vis[1005][1005];
int sum[1005][1005];
double dfs(int x,int y){
	if(x==0||x==n+1||y==0||y==n+1) return 0;
	//cout<<x<<" "<<y<<endl;
	if(vis[x][y]) return ans[x][y]/max(1,sum[x][y]);
	//if(x==3&&y==2)
	//  cout<<x<<" "<<y<<endl;
	vis[x][y]=1;
	double ss=m;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(a[tx][ty]<=a[x][y]) continue;
		ss+=dfs(tx,ty);
		//cout<<x<<" "<<y<<" "<<tx<<" "<<ty<<endl;
			//if(x==3&&y==2) cout<<tx<<" "<<ty<<endl;
	}
	//cout<<endl;
	//printf("%f %d\n",ss,sum[x][y]);
	//cout<<ss<<" "<<ss/sum[x][y]<<" "<<x<<" "<<y<<endl;
	ans[x][y]=ss;
	return ans[x][y]/max(1,sum[x][y]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>a[i][j];
	for(int i=0;i<=n;i++){
		a[0][i]=10005;
		a[i][0]=10005;
		a[n+1][i]=10005;
		a[i][n+1]=10005;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		for(int k=-1;k<=1;k+=2){
			if(a[i][j]>a[i+k][j]) sum[i][j]++;
			if(a[i][j]>a[i][j+k]) sum[i][j]++;
		}
	}
	/*cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<sum[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(!a[i][j]) dfs(i,j);
	//printf("%f",ans[1][1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(!a[i][j]) printf("%.6f ",ans[i][j]);
			else cout<<"0 ";
		}
		if(!a[i][n]) printf("%.6f\n",ans[i][n]);
		else cout<<0<<endl;
	}
	return 0;
}
