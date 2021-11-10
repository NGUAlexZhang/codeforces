#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,s;
		cin>>n>>s;
		int t=(n/2);
		if(n%2==0) t--;
		int ans=(s)/(n-t);
		if(ans<0) cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
//1 1 1 4 4 4 4 