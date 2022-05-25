#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll a,b;
		cin>>a>>b;
		if(a<b) swap(a,b);
		ll x=(a-b)/2;
		x=min(x,min(a,b));
		a-=3*x;
		b-=x;
		cout<<x+min(a,b)/2<<endl;
	}
	return 0;
}
