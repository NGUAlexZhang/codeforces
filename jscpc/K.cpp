#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	/*int ans=1;
	for(int i=0;i<=100000000;i++){
		ans+=(i+1)*2pow()
	}*/
	int T;
	cin>>T;
	while(T--){
		ll k;
		cin>>k;
		if(k==1){
			cout<<0<<endl;
			continue;
		}
		ll len=1;
		int index=0;
		for(int i=1;i<=60;i++){
			if(len+(1ll<<(i-1))*i>=k){
				index=i;
				break;
			}
			len+=(1ll<<(i-1))*i;
		}
		cout<<index<<endl;
	}
	return 0;
}
