#include <bits/stdc++.h>
#define ll long long
using namespace std;
unsigned int sum[5002][5002];
int main(){
	//cout<<sum[0][0];
	int n,r;
	cin>>n>>r;
	r=min(r,5001);
	for(int i=1;i<=n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		sum[x+1][y+1]+=w;
	}
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
		}
	}
	unsigned int ans=0;
	for(int i=r;i<=5001;i++){
		for(int j=r;j<=5001;j++){
			ans=max(ans,sum[i][j]-sum[i-r][j]-sum[i][j-r]+sum[i-r][j-r]);
		}
	}
	cout<<ans;
	return 0;
}
