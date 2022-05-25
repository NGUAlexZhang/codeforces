#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll C[505][505],dp[505][505];
ll n,x;
ll qpow(ll x, ll n){
    ll res = 1;
    while(n){
        if(n & 1) res =res * x % MOD;
        x = x * x % MOD;
        n/=2;
    }
    return res;
}
ll dfs(ll tot,ll maxn){
	if(tot==0||maxn==0) return 1;
	if(tot==1&&maxn>0) return 0;
	if(dp[tot][maxn]!=-1) return dp[tot][maxn];
	//cout<<tot<<" "<<maxn<<endl;
	dp[tot][maxn]=0;
	if(maxn<=(tot-1)){
		//cout<<"fff"<<endl;
		return dp[tot][maxn]=qpow(maxn,tot);
	}
	//cout<<"fff"<<endl;
	for(int i=0;i<=n;i++){
		dp[tot][maxn]+=dfs(i,max(0ll,maxn-tot+1))*C[tot][i]%MOD*qpow((tot-1),tot-i)%MOD;
		dp[tot][maxn]%=MOD;
	}
	return dp[tot][maxn];
}
int main(){
	//cout<<qpow(1,3);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=500;i++) C[i][0]=1;
	for(int i=1;i<=500;i++){
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];C[i][j]%=MOD;
		}
	}
	
	cin>>n>>x;
	cout<<dfs(n,x);	
	return 0;
}
