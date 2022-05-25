#include <bits/stdc++.h>
using namespace std;
double dp[1000005][5][5],a[100005];
double get(int x,int y){
	return sqrt((a[x]-a[y])*(a[x]-a[y])+(x-y)*(x-y));
}
int main(){
	int n;
	cin>>n;
	//memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=2;j++){
			dp[i][j][0]=dp[i][j][1]=2147483647;
		}
	}
	for(int i=1;i<=n+1;i++){
		dp[i][0][0]=dp[i-1][0][0]+get(i,i-1);
		if(i!=n+1)
		dp[i][1][1]=dp[i-1][0][0];
		if(i>=2)
		dp[i][1][0]=min(dp[i-1][1][1]+get(i,i-2),dp[i-1][1][0]+get(i,i-1));
		if(i!=n+1)
		if(i>=2)
		dp[i][2][1]=min(dp[i-1][1][0],dp[i-1][1][1]);
		if(i>=3)
		dp[i][2][0]=min(dp[i-1][2][0]+get(i,i-1),
		min(dp[i-3][0][0]+get(i,i-3),dp[i-2][1][0]+get(i,i-2)));
	}
	/*for(int i=1;i<=n+1;i++){
		for(int j=0;j<=2;j++){
			//cout<<i<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
			cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
		}
	}*/
	printf("%.16f",dp[n+1][2][0]);
	return 0;
}
