#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		vector<int>cnt(100);
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x==0) continue;
			sum++;
			for(int i=0;i<=30;i++){
				if((x>>i)&1) cnt[i+1]++;
			}
		}
		int minn=0;
		for(int i=1;i<=31;i++)
			if(cnt[i]){
				minn=cnt[i];
				break;
			}
		for(int i=1;i<=31;i++)
			if(cnt[i]){
				minn=gcd(minn,cnt[i]);
			}
		if(sum==0){
			for(int i=1;i<=n;i++) cout<<i<<" ";
			cout<<endl;
			continue;
		}
		for(int i=1;i<=minn;i++){
			if(minn%i==0) cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*
6
3 5 3 1 7 1
011
100
011
000
111
001
*/