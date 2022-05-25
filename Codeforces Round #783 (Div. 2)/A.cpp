#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		long long n,m;
		cin>>n>>m;
		if(n>m) swap(n,m);
		if(n==1){
			if(m>2){
				puts("-1");
				continue;
			}
		}
		cout<<(n-1)*2+(m-n)*2-(m-n)%2<<endl;
	}
	return 0;
}