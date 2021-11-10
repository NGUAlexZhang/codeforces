#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,m,k;
		cin>>n>>m>>k;
		k-=2;
		if(k<0){
			puts("NO");
			continue;
		}
		if(m<n-1){
			puts("NO");
			continue;
		}
		if(m>n*(n-1)/2){
			puts("NO");
			continue;
		}
		if(k==0){
			if(n==1) puts("YES");
			else puts("NO");
			continue;
		}
		if(k==1){
			if(n*(n-1)/2==m){
				puts("YES");
			}
			else puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}
