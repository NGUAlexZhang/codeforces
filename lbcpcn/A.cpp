#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll s,p;
	cin>>s>>p;
	int flag=0;
	for(ll i=1;i*i<=p;i++){
		if(p%i==0){
			if(i+(p/i)==s) flag=1;
		}
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
	return 0;
}