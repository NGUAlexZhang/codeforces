#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e9+7;
ll a[150000],sum[150000],dp[100005][500];
int main(){
	int T;
	cin>>T;
	while(T-->0){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int k=0;
		while(k*(k+1)/2<n) k++;
		for(int i=1;i<=k;i++) dp[n+1][i]=-inf;
		dp[n+1][0]=inf;
		for(int i=n;i>=1;i--){
			for(int j=0;j<=k;j++){
				dp[i][j]=dp[i+1][j];
				if(j&&i+j-1<=n&&sum[i+j-1]-sum[i-1]<dp[i+j][j-1]){
					dp[i][j]=max(dp[i][j],sum[i+j-1]-sum[i-1]);
				}
			}
		}
		//cout<<dp[3][1]<<endl;
		int ans=0;
		for(int i=1;i<=k;i++)
			if(dp[1][i]>0){
				//cout<<i<<" "<<dp[1][i]<<endl;
				ans=i;
			}
		cout<<ans<<endl;
	}
	return 0;
}
