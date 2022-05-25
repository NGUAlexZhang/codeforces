#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans=sqrt(n);
		for(int i=1;i*i*i<=n&&i<=1e3;i++){
			int x=i*i*i;
			int tmp=sqrt(x);
			if(tmp*tmp==x) continue;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
