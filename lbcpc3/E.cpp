#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[150000];
int main(){
	int n;
	cin>>n;
	ll sum=0,maxn=-1;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i],maxn=max(maxn,a[i]);
	if(sum%2||sum/2<maxn){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}
	return 0;
}
