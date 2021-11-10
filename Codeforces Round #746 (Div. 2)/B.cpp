#include <bits/stdc++.h>
using namespace std;
int a[150000],b[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(i-x>=1||i+x<=n) continue;
			if(a[i]!=b[i]) flag=1;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
