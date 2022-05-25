#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[105],b[105],tmp[105],sum;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
}
int main(){
	int n,kk;
	n=read(),kk=read();
	map<int,ll>dp[105][105];
	map<int,bool>ex[105][105];
	for(int i=1;i<=n;i++) {
		a[i]=read(),b[i]=read();
		tmp[i]=tmp[i-1]+b[i];
		sum+=b[i];
	}
	/*for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++){
		for(int k=-2*sum-40;k<=2*sum+40;k++) dp[i][j][k]=-1000000000005;
	}*/
	dp[0][0][0]=0;
	ex[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,kk);j++){
			for(int k=-2*tmp[i];k<=2*tmp[i];k++){
				ll mx=-1000000000005;
				if(ex[i-1][j][k])
					mx=dp[i-1][j][k];
				if(j){
					//mx=max(mx,max(dp[i-1][j-1][k+2*b[i]],dp[i-1][j-1][k-2*b[i]])+a[i]);
					if(ex[i-1][j-1][k+2*b[i]])
						mx=max(mx,dp[i-1][j-1][k+2*b[i]]+a[i]);
					if(ex[i-1][j-1][k-2*b[i]])
						mx=max(mx,dp[i-1][j-1][k-2*b[i]]+a[i]);
				}
				//mx=max(mx,max(dp[i-1][j][k+b[i]],dp[i-1][j][k-b[i]])+a[i]);
				if(ex[i-1][j][k+b[i]])
					mx=max(mx,dp[i-1][j][k+b[i]]+a[i]);
				if(ex[i-1][j][k-b[i]])
					mx=max(mx,dp[i-1][j][k-b[i]]+a[i]);
				if(mx!=-1000000000005){
					dp[i][j][k]=mx;
					ex[i][j][k]=1;
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=kk;i++){
		ans=max(ans,dp[n][i][0]);
	}
	cout<<ans;
	return 0;
}
