#include <bits/stdc++.h>
#define fls cout.flush()
#define ll long long
using namespace std;
ll ask(ll l,ll r){
	cout<<"? "<<l<<" "<<r<<"\n";fls;
	ll x;
	cin>>x;
	return x;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll i=0;
		ll l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ask(1,mid)){
				r=mid-1;
			}
			else{
				i=mid;
				l=mid+1;
			}
		}
		ll j=ask(i,n)-ask(i+1,n)+i+1;
		ll k=ask(j,n)-ask(j+1,n)+j;
		j--;
		cout<<"! "<<i<<" "<<j+1<<" "<<k<<"\n";
		fls;
	}
	return 0;
}
