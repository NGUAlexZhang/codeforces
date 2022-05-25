#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[250000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		m-=a[n];
		if(m<0){
			puts("NO");
			continue;
		}
		for(int i=n;i>1;i--){
			m-=a[i];
			m-=1;
			if(m<0){
				break;
			}
		}
		if(m<=0){
			puts("NO");
		}
		else{
			puts("YES");
		}
	}
	return 0;
}
