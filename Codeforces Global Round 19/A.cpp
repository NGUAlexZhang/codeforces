#include <bits/stdc++.h>
using namespace std;
int a[150000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool flag=0;
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1]) flag=1;
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
