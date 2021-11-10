#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll C[65][65];
int main(){
	for(int i=0;i<=60;i++){
		C[i][0]=1;
	}
	for(int i=1;i<=60;i++){
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j]);
		}
	}
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int tot1=0,tot0=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			sum+=x;
			if(x==1) tot1++;
			if(x==0) tot0++;
		}
		if(sum==0){
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		for(int i=0;i<=tot0;i++){
			ans+=C[tot0][i];
		}
		ans*=tot1;
		//if(sum==1) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
