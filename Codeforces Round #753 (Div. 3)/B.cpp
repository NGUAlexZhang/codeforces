#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll x,n;
		cin>>x>>n;
		if((n/2)%2){
			if(x%2) x--;
			else x++;
		}
		if(n%2){
			if(x%2) x+=n;
			else x-=n;
		}
		cout<<x<<endl;
	}
	return 0;
}
