#include <bits/stdc++.h>
using namespace std;
char s[350005];
int sum[350005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,q;
		cin>>n>>q;
		cin>>(s+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1];
			int x=(s[i]=='+'?1:-1);
			x*=(i%2?1:-1);
			sum[i]+=x;
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			if(sum[r]==sum[l-1]){
				cout<<0<<endl;
				continue;
			}
			int x=sum[r]-sum[l-1];
			if(x%2) cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
	return 0;
}