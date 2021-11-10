#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1<<20][21],a[25][25];
int main(){
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=(1<<n)-1;i++){
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) continue;
			for(int k=1;k<=n;k++){
				if(((i>>(k-1))&1)==0) continue;
				dp[i|(1<<(j-1))][j]=min(dp[i|(1<<(j-1))][j],dp[i][k]+a[k][j]);
			}
		}
	}
	cout<<dp[(1<<n)-1][n];
	return 0;
}