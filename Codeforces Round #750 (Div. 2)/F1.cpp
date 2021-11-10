#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int dp[1005];
int main(){
	for(int i=1;i<=1000;i++) dp[i]=100000;
	scanf("%d",&n);
	dp[0]=-1;
	bool flag=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=0;j<=512;j++){
			if(dp[j]<x){
				if(j==x) {
					flag=1;continue;
				}
				dp[j^x]=min(dp[j^x],x);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=512;i++){
		if(dp[i]!=dp[1000]) ans++;
	}
	cout<<ans+1<<endl;
	cout<<0<<" ";
	for(int i=1;i<=900;i++)
		if(dp[i]!=dp[1000])
			cout<<i<<" ";
	return 0;
}
