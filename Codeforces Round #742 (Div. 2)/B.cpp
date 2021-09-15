#include <bits/stdc++.h>
using namespace std;
int pre[1000005];
int main(){
	for(int i=1;i<=1000000;i++) pre[i]=pre[i-1]^i;
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		int ans=a;
		if(pre[a-1]!=b){
		if((pre[a-1]^a)==b) ans+=2;
		else ans++;
	}
		//cout<<pre[a-1]<<" "<<a<<" "<<(pre[a-1]^a)<<endl;
		cout<<ans<<endl;
	}
	return 0;
}