#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x;
int ans=-1;
int length(ll x){
	int len=0;
	while(x){
		len++;
		x/=10;
	}
	return len;
}
set<int> getNumbers(ll x){
	set<int>v;
	while(x){
		v.insert(x%10);
		x/=10;
	}
	return v;
}
void dfs(ll x,int step){
	if(length(x)==n){
		if(ans==-1) ans=step;
		else ans=min(ans,step);
		return;
	}
	if(ans!=-1&&step+(n-length(x))>=ans) return;
	set<int>v=getNumbers(x);
	for(auto i:v){
		if(i!=1)
		dfs(x*i,step+1);
	}
}
int main(){
	cin>>n>>x;
	dfs(x,0);
	cout<<ans;
	return 0;
}
