#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=1e9+7;
ll a[1000005];
int main(){
	a[1]=1;
	ll now=12,cnt=18;
	for(int i=2;i<=2e5;i++){
		a[i]=a[i-1]*now;
		a[i]%=Mod;
		now+=cnt;
		now%=Mod;
		cnt+=8;
		cnt%=Mod;	
	}
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
