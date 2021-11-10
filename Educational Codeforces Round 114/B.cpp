#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10];
int main(){
	int T;
	cin>>T;
	while(T--){
		ll m;
		cin>>a[1]>>a[2]>>a[3]>>m;
		//a[1]--,a[2]--,a[3]--;
		//if()
		sort(a+1,a+4);
		if(a[1]+a[2]+a[3]-3<m){
			cout<<"NO"<<endl;
			continue;
		}
		a[3]-=a[2];
		a[3]-=a[1];
		if(a[3]-1<=m){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
