#include <bits/stdc++.h>
using namespace std;
int n;
int f[30],dp[30];
int main(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=12;i++) f[i]=2*f[i-1]+1;
	dp[0]=0;
	for(int i=1;i<=12;i++){
		for(int j=0;j<i;j++){
			dp[i]=min(dp[i],2*dp[j]+f[i-j]);
		}
		cout<<dp[i]
	}
	return 0;
}
