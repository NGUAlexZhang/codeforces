#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		n--;
		ll tim=0;
		ll kk=2;
		for(ll i=0;pow(kk,i)<=k&&n>0;i++){
			ll num=pow(kk,i);
			tim++;	
			if(n<=num){
				n=0;
				break;
			}
			n-=num;
		}
		if(n==0){
			cout<<tim<<endl;
			continue;
		}
		//cout<<n<<endl;
		tim+=n/k;
		if(n%k) tim++;
		cout<<tim<<endl;
	}
	return 0;
}
