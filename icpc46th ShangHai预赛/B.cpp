#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
int opt[100005],x[100005],t[100005],a[100005],b[100005];
int main(){
	int	n,m;
	ll suma=0,sumb=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=MOD;
		suma+=a[i];
		suma%=MOD;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		b[i]%=MOD;
		sumb+=b[i];
		sumb%=MOD;
	}
	int q;
	ll ans=0;
	cin>>q;
	map<int,bool>k[5];
	for(int i=1;i<=q;i++) cin>>opt[i]>>x[i]>>t[i];
	while(q){
		if(k[opt[q]][x[q]]) {
			q--;
			continue;
		}
		k[opt[q]][x[q]]=1;
		if(opt[q]==1){
			ans=(ans+sumb*a[x[q]]%MOD*t[q]%MOD)%MOD;
			suma=(suma-a[x[q]]+MOD)%MOD;
		}
		else{
			ans=(ans+suma*b[x[q]]%MOD*t[q])%MOD;
			sumb=(sumb-b[x[q]]+MOD)%MOD;
		}
		q--;
	}
	cout<<ans;
	return 0;
}
